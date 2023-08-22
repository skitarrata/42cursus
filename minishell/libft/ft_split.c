/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:11:42 by svalenti          #+#    #+#             */
/*   Updated: 2021/01/19 19:23:38 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && count == 0)
		{
			count = 1;
			i++;
		}
		else if (*str == c)
			count = 0;
		str++;
	}
	return (i);
}

char		**ft_split(char const *s, char c)
{
	char	**split;
	char	*start;
	size_t	i;
	size_t	size;

	if (!s || !(split = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1))))
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			size = s - start + 1;
			if (!(split[i] = (char *)malloc(size)))
				return (0);
			ft_strlcpy(split[i++], start, size);
		}
		else
			s++;
	}
	split[i] = 0;
	return (split);
}
