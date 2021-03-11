/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:45:16 by svalenti          #+#    #+#             */
/*   Updated: 2021/03/11 18:34:19 by svalenti         ###   ########.fr       */
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
# include "minilibx_mms_20200219/mlx.h"

# define mapR 24
# define mapC 24
# define resolutionX 620
# define resolutionY 480
//# define texWidth 64
//# define texHeight 64
# define SPEEDMOVE 0.3
# define ROTATESPEED 0.1

typedef struct	s_pos
{
	unsigned int			color;
	void		*img;
	void 		*mlx;
	void 		*ide_win;	
	char		*addr;
	int			endian;
	int			bits_per_pixel;
	int			line_length;
	int			keyboard[256];
	char		*relative_path;

	int			texWidth;
	int 		texHeight;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		pianoX;
	double		pianoY;

	double 		cameraX;
    double		rayDirX; //raggio laser
    double		rayDirY;
	int			mapX; //casella mappa
    int			mapY;
	double 		sideDistX; //distanza dalla posizione iniziale del raggio (pos) al primo lato o destro o sinistro, dip dalla componente del raggio
    double 		sideDistY; 

	double 		deltaDistX; // distanza che il raggio deve percorrere per andare da 1 lato x al successivo lato x, viceversa
    double 		deltaDistY;
    double 		perpWallDist; //verrà utilizzata per calcolare la lunghezza del raggio
	int 		stepX; //controllo delle componenti
    int 		stepY;

    int 		side; //ci serve per capire su quale lato abbiamo colpito il muro
	int			lineHeight; // lunghezza da disegnare
	int			drawStart; // punto in cui inizio a colorare
	int			drawEnd; //punto in cui finisco di colorare

	unsigned int texture[8][4160];
}				t_pos;

#endif