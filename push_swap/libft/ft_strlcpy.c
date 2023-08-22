/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:44:25 by grusso            #+#    #+#             */
/*   Updated: 2021/06/11 17:53:05 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict d, const char *restrict s, size_t n)
{
	size_t	l;
	size_t	i;

	i = 0;
	if (!d || !s)
		return (0);
	l = ft_strlen(s);
	if (n > 0)
	{
		while (s[i] && i < (n - 1))
		{
			d[i] = s[i];
			i++;
		}
		d[i] = 0;
	}
	return (l);
}
