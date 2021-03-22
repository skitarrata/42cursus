/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:45:16 by svalenti          #+#    #+#             */
/*   Updated: 2021/03/18 18:04:53 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include "minilibx-linux/mlx.h"

# define mapR 24
# define mapC 24
# define resolutionX 620
# define resolutionY 480
# define TEXUR 11
# define SPEEDMOVE 0.4
# define ROTATESPEED 0.2
# define numSprites 19

typedef struct s_tex
{
	void		*tex;
	int			texWidth;
	int 		texHeight;
	char		*addrestex;
}				t_tex;

typedef struct	s_pos
{
	void		*img;
	void 		*mlx;
	void 		*ide_win;	
	char		*addr;
	int			endian;
	int			bits_per_pixel;
	int			line_length;
	int			keyboard[256];

	t_tex		strutex[TEXUR];

	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		pianoX;
	double		pianoY;

	double 		cameraX;
    double		rayDirX; //raggio laser
    double		rayDirY;
	//double		rayDirX0;
	//double		rayDirY0;
	//double		rayDirX1;
	//double		rayDirY1;
	int			mapX; //casella mappa
    int			mapY;
	double 		sideDistX; //distanza dalla posizione iniziale del raggio (pos) al primo lato o destro o sinistro, dip dalla componente del raggio
    double 		sideDistY; 

	double 		deltaDistX; // distanza che il raggio deve percorrere per andare da 1 lato x al successivo lato x, viceversa
    double 		deltaDistY; //   %
    double 		perpWallDist; //verrà utilizzata per calcolare la lunghezza del raggio  %
	int 		stepX; //controllo delle componenti  %
    int 		stepY;  //  %

    //int 		side; //ci serve per capire su quale lato abbiamo colpito il muro  %
	//int			lineHeight; // lunghezza da disegnare   %
	int			drawStart; // punto in cui inizio a colorare
	int			drawEnd; //punto in cui finisco di colorare
}				t_pos;



void			clear_textures(t_pos *pos);
static void		load_tex(t_pos *pos);
void 			ft_floor_tex(t_pos *pos, int x);
int				press_button(t_pos *pos);
static void		move_W(t_pos *pos);
static void		move_A(t_pos *pos);
static void		move_D(t_pos *pos);
static void		move_S(t_pos *pos);
int 			ft_key_release(int keycode, t_pos *pos);
int 			ft_key_hit(int keycode, t_pos *pos);
void			first_pos(t_pos *pos);
static void		ft_calcolate(t_pos *pos);
void			my_mlx_pixel_put(t_pos *data, int x, int y, int color);

#endif