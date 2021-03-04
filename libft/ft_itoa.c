/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:35:21 by svalenti          #+#    #+#             */
/*   Updated: 2021/01/17 18:27:18 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dim(int n)
{
	int	dim;

	dim = 0;
	if (n <= 0)
	{
		dim++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		dim++;
	}
	return (dim);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;
	size_t	i;

	nb = n;
	nb = nb > 0 ? nb : -nb;
	i = ft_dim(n);
	if (!(str = (char *)malloc((sizeof(char)) * (i + 1))))
		return (0);
	*(str + i--) = 0;
	while (nb > 0)
	{
		*(str + i--) = nb % 10 + '0';
		nb /= 10;
	}
	if (i == 0 && str[1] == '\0')
		*(str + i) = '0';
	else if (i == 0 && str[1] != '\0')
		*(str + i) = '-';
	return (str);
}
