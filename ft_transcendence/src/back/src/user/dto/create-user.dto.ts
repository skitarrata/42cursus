import { IsNotEmpty } from 'class-validator';

export class QualityImageDto {
  @IsNotEmpty()
  large: string;
  @IsNotEmpty()
  medium: string;
  @IsNotEmpty()
  small: string;
  @IsNotEmpty()
  micro: string;
}

export class ImageDto {
  @IsNotEmpty()
  link: string;
  versions: QualityImageDto;
}

export class CreateUserDto {
  @IsNotEmpty()
  id: number;
  @IsNotEmpty()
  login: string;
  @IsNotEmpty()
  image: ImageDto;
}
