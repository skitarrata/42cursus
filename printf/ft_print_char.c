/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:01:27 by svalenti          #+#    #+#             */
/*   Updated: 2021/02/09 17:05:29 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space_char(t_data *data)
{
	int		i;
	char	a;

	i = data->width;
	a = data->zero ? '0' : ' ';
	if (i > 1)
	{
		i += -1;
		while (i-- > 0)
			ft_putchar_fd(a, 1);
	}
	return ;
}

int		ft_print_char(va_list ap, t_data *data)
{
	int c;
	int count;

	count = 0;
	if (data->l_type == 'c')
	{
		c = va_arg(ap, int);
		count = 1;
		if (data->minus == 0)
			print_space_char(data);
		ft_putchar_fd(c, 1);
		if (data->minus == 1)
			print_space_char(data);
	}
	else if (data->l_type == '%')
	{
		count = 1;
		if (data->minus == 0)
			print_space_char(data);
		ft_putchar_fd('%', 1);
		if (data->minus == 1)
			print_space_char(data);
	}
	return (count > data->width || count == 0 ? count : data->width);
}
