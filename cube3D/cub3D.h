/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:45:16 by svalenti          #+#    #+#             */
/*   Updated: 2021/03/04 17:48:05 by svalenti         ###   ########.fr       */
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

typedef struct	s_data
{
	void		*img;
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
	double		timefps;
	double		oldtime;
}				t_pos;

#endif