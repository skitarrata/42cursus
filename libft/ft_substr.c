/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:53:31 by svalenti          #+#    #+#             */
/*   Updated: 2021/01/18 12:03:53 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		count;
	size_t				i;
	char				*str;

	i = 0;
	if (!s)
		return (0);
	count = ft_strlen(s);
	if (!(str = (char *)malloc((sizeof(char)) * (len + 1))))
		return (0);
	if (count < start)
	{
		str[0] = '\0';
		return (str);
	}
	while (i < len)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
