/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:17:04 by svalenti          #+#    #+#             */
/*   Updated: 2021/04/10 18:59:34 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_conversion_rgb(int t, int r, int g, int b) // da verificare
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_count_map(t_pos *pos)
{
	char	*str;
	int		fd;
	int		count;
	int		i;
	int		tmp;

	count = 0;
	i = 0;
	pos->rowmap = 0;
	if (!(fd = open("./map/map.cub", O_RDONLY)))
	{
		printf("\nError open\n");
		return ;
	}
	while (get_next_line(fd, &str))
	{
		while (str[i] == ' ' && count == 0)
		{
			i++;
			if (str[i] == '1')
			{
				i = 0;
				count = 1;
			}
		}
		if (count = 1)
		{
			tmp = ft_strlen(str);
			if (tmp > pos->colmap)
				pos->colmap = tmp;
			pos->rowmap++;
		}
	}
}

int		**allocation_mat(t_pos *pos)
{
	int		**map;
	int		i;

	i = 0;
	if (!(map = (int **)malloc(sizeof(int *) * (pos->rowmap))))
		return (0);
	while (i < pos->colmap)
		map[i++] =  (int *)malloc(sizeof(int) * (pos->colmap));
	return (map);
}

int		**ft_read_map(t_pos *pos, int fd)
{
	int		dim;
	char	*buf;
	int		**map;
	int		i,j;
	int 	countmap;

	j = 0;
	countmap = 0;
	pos->pianoX = 0;
	pos->pianoY = 0.66;
	map = allocation_mat(pos);
	while (get_next_line(fd, &buf))
	{
		i = 0;
		dim = ft_strlen(buf);
		while (buf[i] == ' ' && countmap == 0)
		{
			i++;
			if (buf[i] == '1')
				countmap = 1;
		}
		if (buf[i] >= 65 && buf[i] <= 90)
		{
			if (buf[i] == 'R')
			{
				while (i < dim)
				{
					int count = 0;

					while (buf[i] == ' ')
						i++;
					while (buf[i] >= 48 && buf[i] <= 57 && count == 0)
						pos->resolutionX = ((pos->resolutionX * 10) + (buf[i++] - '0')); //resolution da mettere in pos
					if (pos->resolutionX)
						count = 1;
					while (buf[i] >= 48 && buf[i] <= 57 && count)
						pos->resolutionY = ((pos->resolutionY * 10) + (buf[i++] - '0'));
					i++;
				}
			}
			else if (buf[i] == 'F')
			{
				int r = 0;
				int g = 0;
				int b = 0;

				while (i < dim)
				{
					int count = 0;

					while (buf[i] == ' ' || buf[i] == ',')
						i++;
					while (buf[i] >= 48 && buf[i] <= 57 && count == 0)
						r = ((r * 10) + (buf[i++] - '0'));
					if (r)
						count = 1;
					while (buf[i] >= 48 && buf[i] <= 57 && count == 1)
						g = ((g * 10) + (buf[i++] - '0'));
					if (g)
						count = 2;
					while (buf[i] >= 48 && buf[i] <= 57 && count == 1)
						b = ((b * 10) + (buf[i++] - '0'));
					i++;
				}
				pos->floor = ft_conversion_rgb(0, r, g, b); // da includere in pos o lista a parte 
			}
			else if (buf[i] == 'C')
			{
				int r = 0;
				int g = 0;
				int b = 0;

				while (i < dim)
				{
					int count = 0;

					while (buf[i] == ' ' || buf[i] == ',')
						i++;
					while (buf[i] >= 48 && buf[i] <= 57 && count == 0)
						r = ((r * 10) + (buf[i++] - '0'));
					if (r)
						count = 1;
					while (buf[i] >= 48 && buf[i] <= 57 && count == 1)
						g = ((g * 10) + (buf[i++] - '0'));
					if (g)
						count = 2;
					while (buf[i] >= 48 && buf[i] <= 57 && count == 1)
						b = ((b * 10) + (buf[i++] - '0'));
					i++;
				}
				pos->cel = ft_conversion_rgb(0, r, g, b); // da includere in pos o lista a parte 
			}
			else if (buf[i] == 'N' && buf[i++] == 'O')
			{
				while (buf[i] == ' ')
					i++;
				if (buf[i] == '.' && buf[i + 1] == '/')
					pos->nametex = ft_strdup(&buf[i]); //da includere nemetex e verificare sta cosa :( vedere dove mettere il free
			}
			else if (buf[i] == 'S' && buf[i++] == 'O')
			{
				while (buf[i] == ' ')
					i++;
				if (buf[i] == '.' && buf[i + 1] == '/')
					pos->nametex = ft_strdup(&buf[i]);
			}
			else if (buf[i] == 'W' && buf[i++] == 'E')
			{
				while (buf[i] == ' ')
					i++;
				if (buf[i] == '.' && buf[i + 1] == '/')
					pos->nametex = ft_strdup(&buf[i]);
			}
			else if (buf[i] == 'E' && buf[i++] == 'A')
			{
				while (buf[i] == ' ')
					i++;
				if (buf[i] == '.' && buf[i + 1] == '/')
					pos->nametex = ft_strdup(&buf[i]);
			}
			else if (buf[i] == 'S')
			{
				while (buf[i] == ' ')
					i++;
				if (buf[i] == '.' && buf[i + 1] == '/')
					pos->namesprite = ft_strdup(&buf[i]); //da includere nemesprite vedere dove mettere il free
			}
		}
		else if (buf[i] == ' ' || buf[i] == '1')
		{
			while (i < pos->colmap)
			{
				map[j][i] = buf[i];
				if (map[j][i] == 'N')
				{
					pos->posX = j;
					pos->posY = i;
					pos->dirX = -1;
					pos->dirY = 0;
				}
				if (map[j][i] == 'S')
				{
					pos->posX = j;
					pos->posY = i;
					pos->dirX = 1;
					pos->dirY = 0;
				}
				if (map[j][i] == 'W')
				{
					pos->posX = j;
					pos->posY = i;
					pos->dirX = 0;
					pos->dirY = -1;
				}
				if (map[j][i] == 'E')
				{
					pos->posX = j;
					pos->posY = i;
					pos->dirX = 0;
					pos->dirY = 1;
				}
				i++;
			}
			j++;
		}
	}
}

//questa roba e da includere nel main principale
int main ()
{
	int fd;
	t_pos pos;

	ft_count_map(&pos);
	if (!(fd = open("./map/map.cub", O_RDONLY)))
	{
		printf("\nError open\n");
		return (0);
	}
	ft_read_map(&pos, fd); //ovviamente pos al momento non c e
	close(fd);
}