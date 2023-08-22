/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:30:34 by svalenti          #+#    #+#             */
/*   Updated: 2021/01/18 11:43:41 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	dim1;
	size_t	dim2;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	dim1 = ft_strlen((char *)s1);
	dim2 = ft_strlen((char *)s2);
	if (!(str = (char *)malloc((sizeof(char)) * (dim1 + dim2 + 1))))
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}
