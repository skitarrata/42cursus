/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:45:16 by svalenti          #+#    #+#             */
/*   Updated: 2021/04/13 18:44:00 by grusso           ###   ########.fr       */
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
# include <mlx.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# define mapR 24
# define mapC 24
//# define resolutionX 640
//# define resolutionY 480
# define TEXUR 11
# define SPEEDMOVE 0.1
# define ROTATESPEED 0.1
# define numSprites 19

typedef struct	s_tex
{
	void		*tex;
	int			texWidth;
	int 		texHeight;
	char		*addrestex;
	char		*nametex;
}				t_tex;

typedef struct	s_pos
{
	int 		**map;
	int			save;

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
	int			resolutionX;
	int			resolutionY;
	int			floor;
	int			cel;
	int			colmap;
	int			rowmap;

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

typedef struct	s_sprite
{
  double x;
  double y;
  int texture;
}				t_sprite;

void			clear_textures(t_pos *pos);
void			load_tex(t_pos *pos);
void 			ft_floor_tex(t_pos *pos, int x);
int				press_button(t_pos *pos);
void			move_w(t_pos *pos);
void			move_a(t_pos *pos);
void			move_d(t_pos *pos);
void			move_s(t_pos *pos);
int 			ft_key_release(int keycode, t_pos *pos);
int 			ft_key_hit(int keycode, t_pos *pos);
void			first_pos(t_pos *pos);
void			ft_calcolate(t_pos *pos);
void			my_mlx_pixel_put(t_pos *data, int x, int y, int color);
void			sortSprites(int *order, double *dist, int amount);
void			scambia(double *a, double *b);
int				exit_game(t_pos *pos);
int				screenshot(t_pos *pos);
int				ft_conversion_rgb(int t, int r, int g, int b);
void			ft_count_map(t_pos *pos);
int				**allocation_mat(t_pos *pos);
int				**ft_read_map(t_pos *pos, int fd);
void			ft_set_pos(t_pos *pos);

#endif
