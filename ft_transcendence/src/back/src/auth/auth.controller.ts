import {
  Body,
  ClassSerializerInterceptor,
  Controller,
  Get,
  Post,
  Req,
  Res,
  UseGuards,
  UseInterceptors,
  Query,
  HttpCode,
  UnauthorizedException,
} from '@nestjs/common';
import { UserService } from '../user/user.service';
import { Request, Response } from 'express';
import { AuthGuard } from './auth.guard';
import { JwtService } from '@nestjs/jwt';
import { TwoFactorAuthenticationService } from './twoFactorAuthentication.service';
import { UpdateUser } from 'src/user/dto/update-user.dto';

@UseInterceptors(ClassSerializerInterceptor)
@Controller()
export class AuthController {
  constructor(
    private readonly user: UserService,
    private readonly jwt: JwtService,
    private readonly twoFaAuthService: TwoFactorAuthenticationService,
    private readonly userService: UserService,
  ) {}

  @UseGuards(AuthGuard)
  @Post('generate')
  @UseInterceptors(ClassSerializerInterceptor)
  async check(@Body('id') id: number, @Res() response: Response) {
    const { otpauthUrl } = await this.twoFaAuthService.generatetwoFaAuthSecret(
      id,
    );

    return this.twoFaAuthService.pipeQrCodeStream(response, otpauthUrl);
  }

  @UseGuards(AuthGuard)
  @Post('turn2fa')
  @HttpCode(200)
  async turnOnTwoFactorAuthentication(
    @Req() request: Request,
    @Body('twoFaAuthCode') code: string,
  ) {
    const cookie = request.cookies['token'];
    const user = await this.user.userCookie(cookie);
    const isCodeValid = this.twoFaAuthService.checkTwoFaAuthCode(code, user);
    if (!isCodeValid) {
      throw new UnauthorizedException('Wrong authentication code');
    }
    await this.userService.turnOnTwoFaAuth(user.id);
  }

  @Post('auth2fa')
  @HttpCode(200)
  async auth2fa(
    @Req() request: Request,
    @Body() data: { twoFaAuthCode: string },
  ) {
    const cookie = request.cookies['token'];

    const user = await this.user.userCookie(cookie);
    const isCodeValid = this.twoFaAuthService.checkTwoFaAuthCode(
      data.twoFaAuthCode,
      user,
    );
    if (!isCodeValid) {
      return false;
    }

    request.res.clearCookie('token');
    const token = await this.jwt.signAsync({ id: user.id, two_fa: false });
    request.res.cookie('token', token, { httpOnly: true });
    return true;
  }

  @Get('login')
  async login(
    @Query('code') code: string,
    @Query('state') path: string,
    @Res({ passthrough: true }) response: Response,
  ): Promise<any> {
    const { user, first } = await this.user.login(code, response);
    if (first) return response.redirect(`http://${process.env.BASE_IP}/`);
    else return response.redirect(`http://${process.env.BASE_IP}${path}`);
  }

  @UseGuards(AuthGuard)
  @Get('user')
  async userCookie(@Req() request: Request) {
    const cookie = request.cookies['token'];
    if (typeof cookie === 'undefined') return { id: null };
    const data = await this.jwt.verifyAsync(cookie);
    const user = await this.user.userCookie(cookie);
    return { ...user, two_fa: data['two_fa'] };
  }

  @UseGuards(AuthGuard)
  @Get('logout')
  async logout(@Res({ passthrough: true }) response: Response) {
    response.clearCookie('token');
    return {
      message: 'Success',
    };
  }
}
