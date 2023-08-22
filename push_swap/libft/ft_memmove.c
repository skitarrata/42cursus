/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:13:02 by grusso            #+#    #+#             */
/*   Updated: 2021/01/14 17:14:22 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*des;
	unsigned char	*res;

	i = 0;
	des = (unsigned char *)str1;
	res = (unsigned char *)str2;
	if (!des && !res)
		return (0);
	if (des > res)
	{
		while (++i <= n)
			des[n - i] = res[n - i];
	}
	else
	{
		while (i < n)
		{
			des[i] = res[i];
			i++;
		}
	}
	return (des);
}
