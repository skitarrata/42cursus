/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:00:56 by svalenti          #+#    #+#             */
/*   Updated: 2021/01/14 16:57:34 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict d, const char *restrict s, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(d);
	if (dstsize <= i)
		return (dstsize + ft_strlen(s));
	while (s[j] != 0 && i + 1 < dstsize)
		d[i++] = s[j++];
	d[i] = 0;
	return (ft_strlen(d) + ft_strlen(&s[j]));
}
