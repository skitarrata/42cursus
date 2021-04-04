/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:21:13 by gabriele          #+#    #+#             */
/*   Updated: 2021/04/02 16:19:39 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static int	write_bmp_header(int fd, int filesize, t_pos *pos)
{
	int				i;
	int				tmp;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	tmp = resolutionX;
	set_int_in_char(bmpfileheader + 18, tmp);
	tmp = resolutionY;
	set_int_in_char(bmpfileheader + 22, tmp);
	bmpfileheader[27] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

static int	get_color(t_pos *pos, int x, int y)
{
	int	rgb;
	int	color;

	color = *(int*)(pos->addr + (4 * resolutionX * (resolutionY - 1 - y)) + (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

static int	write_bmp_data(int file, t_pos *pos, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					color;

	i = 0;
	while (i < resolutionY)
	{
		j = 0;
		while (j < resolutionX)
		{
			color = get_color(pos, j, i);
			if (write(file, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			screenshot(t_pos *pos)
{
	int			filesize;
	int			file;
	int			pad;

	pad = (4 - (resolutionX * 3) % 4) % 4;
	filesize = 54 + (3 * (resolutionX + pad) * resolutionY);
	if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND)) < 0)
		return (0);
	if (!write_bmp_header(file, filesize, pos))
		return (0);
	if (!write_bmp_data(file, pos, pad))
		return (0);
	close(file);
	return (1);
}