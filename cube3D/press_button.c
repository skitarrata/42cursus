/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:31:39 by svalenti          #+#    #+#             */
/*   Updated: 2021/03/24 18:43:42 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int map2[mapR][mapC]=
{
  {8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
  {8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
  {8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
  {8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
  {8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
  {8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
  {7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
  {7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
  {7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
  {7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
  {7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
  {7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
  {2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
  {2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
  {2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
  {1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
  {2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
  {2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
  {2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,9,5,0,5,0,5,0,5},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
  {2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
  {2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
  {2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5}
};

int ft_key_hit(int keycode, t_pos *pos)
{
    pos->keyboard[keycode] = 1;
    return (0);
}

int ft_key_release(int keycode, t_pos *pos)
{
    pos->keyboard[keycode] = 0;
    return (0);
}

int	press_button(t_pos *pos)
{
	/* if (button == 53)
	{
		mlx_destroy_window(pos->mlx, pos->ide_win);
		return (0);
	} */
	if (pos->keyboard[13])
		move_W(pos);
	else if (pos->keyboard[0])
		move_A(pos);
	else if (pos->keyboard[1])
		move_S(pos);
	else if (pos->keyboard[2])
		move_D(pos);
	ft_calcolate(pos);
	return (0);
}

static void	move_W(t_pos *pos)
{
	if (map2[(int)(pos->posX + pos->dirX)] [(int)pos->posY] == 0)
		pos->posX += pos->dirX * SPEEDMOVE;
    if (map2[(int)pos->posX] [(int)(pos->posY + pos->dirY)] == 0)
		pos->posY += pos->dirY * SPEEDMOVE;
	printf("%f\n", pos->posX);
	printf("%f\n", pos->posY);
}

static void	move_S(t_pos *pos)
{
	if (map2[(int)(pos->posX - pos->dirX)] [(int)pos->posY] == 0)
		pos->posX -= pos->dirX * SPEEDMOVE;
    if (map2[(int)pos->posX] [(int)(pos->posY - pos->dirY)] == 0)
		pos->posY -= pos->dirY * SPEEDMOVE;
}

static void	move_A(t_pos *pos)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = pos->dirX;
    pos->dirX = pos->dirX * cos(ROTATESPEED / 2) - pos->dirY * sin(ROTATESPEED / 2);
    pos->dirY = oldDirX * sin(ROTATESPEED / 2) + pos->dirY * cos(ROTATESPEED / 2);
    oldPlaneX = pos->pianoX;
    pos->pianoX = pos->pianoX * cos(ROTATESPEED / 2) - pos->pianoY * sin(ROTATESPEED / 2);
    pos->pianoY = oldPlaneX * sin(ROTATESPEED / 2) + pos->pianoY * cos(ROTATESPEED / 2);
}

static void	move_D(t_pos *pos)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = pos->dirX;
    pos->dirX = pos->dirX * cos(-ROTATESPEED / 2) - pos->dirY * sin(-ROTATESPEED / 2);
    pos->dirY = oldDirX * sin(-ROTATESPEED / 2) + pos->dirY * cos(-ROTATESPEED / 2);
    oldPlaneX = pos->pianoX;
    pos->pianoX = pos->pianoX * cos(-ROTATESPEED / 2) - pos->pianoY * sin(-ROTATESPEED / 2);
    pos->pianoY = oldPlaneX * sin(-ROTATESPEED / 2) + pos->pianoY * cos(-ROTATESPEED / 2);
}