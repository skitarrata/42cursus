/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:04:32 by grusso            #+#    #+#             */
/*   Updated: 2021/06/11 17:52:57 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict d, const char *restrict s, size_t n)
{
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen(d);
	if (n <= l)
		return (n + ft_strlen(s));
	while (s[i] && l + 1 < n)
		d[l++] = s[i++];
	d[l] = 0;
	return (ft_strlen(d) + ft_strlen(&s[i]));
}
