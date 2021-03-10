/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:45:16 by svalenti          #+#    #+#             */
/*   Updated: 2021/03/10 15:48:06 by svalenti         ###   ########.fr       */
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

# define mapR 10
# define mapC 15
# define resolutionX 1920
# define resolutionY 1080

typedef struct	s_data
{
	void		*img;
	void 		*mlx;
	void 		*ide_win;	
	char		*add;
	int			endian;
	int			pixel;
	int			len;
}				t_data;

typedef struct	s_pos
{
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
}				t_pos;

#endif