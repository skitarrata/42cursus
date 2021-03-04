/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:36:17 by svalenti          #+#    #+#             */
/*   Updated: 2021/02/10 13:52:14 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*check_after_nl(char **after_nl, char **line)
{
	char *tmp;

	tmp = NULL;
	if (*after_nl)
	{
		if ((tmp = ft_strchr(*after_nl, '\n')))
		{
			*tmp = 0;
			tmp++;
			*line = ft_strdup(*after_nl);
			ft_strcpy(*after_nl, tmp);
		}
		else
		{
			*line = ft_strdup(*after_nl);
			if (*after_nl)
			{
				free(*after_nl);
				*after_nl = 0;
			}
		}
	}
	else
		*line = ft_strnew(1);
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			byte_read;
	char		*tmp;
	char		*a;
	static char	*after_nl[OPEN_MAX];

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0) || BUFFER_SIZE < 1)
		return (-1);
	tmp = check_after_nl(&after_nl[fd], line);
	while (!tmp && (byte_read = read(fd, &buf, BUFFER_SIZE)))
	{
		buf[byte_read] = 0;
		if ((tmp = ft_strchr(buf, '\n')))
		{
			*tmp++ = 0;
			after_nl[fd] = ft_strdup(tmp);
		}
		else
			after_nl[fd] = 0;
		a = *line;
		*line = ft_strjoin(*line, buf);
		free(a);
	}
	return (byte_read ? 1 : 0);
}
