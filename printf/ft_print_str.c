/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:29:35 by svalenti          #+#    #+#             */
/*   Updated: 2021/02/09 17:04:35 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space(t_data *data, char *str)
{
	int		i;
	int		l;
	int		c;
	char	a;

	c = data->precision;
	l = ft_strlen(str);
	if (data->precision < 0)
		c = 0;
	a = data->zero ? '0' : ' ';
	if (c < l && data->point && !data->widthmin)
	{
		i = data->width - c;
		while (i-- > 0)
			ft_putchar_fd(a, 1);
	}
	else if (l < data->width)
	{
		i = data->width - ft_strlen(str);
		while (i-- > 0)
			ft_putchar_fd(a, 1);
	}
	else
		print_space2(data, str);
	return ;
}

void	print_space2(t_data *data, char *str)
{
	int		n;
	int		c;
	char	a;

	c = data->precision;
	if (data->precision < 0)
		c = 0;
	n = ft_strlen(str) - c;
	a = data->zero ? '0' : ' ';
	if (data->width > n && n > 0)
	{
		data->width -= n;
		while (--data->width > 0)
			ft_putchar_fd(a, 1);
	}
	return ;
}

void	ft_pcchar(char *str, int i, t_data *data)
{
	if (ft_memcmp(str, "(null)", 6) == 0 && data->precision < 0)
		i = 6;
	while (i-- > 0 && *str)
		ft_putchar_fd(*str++, 1);
}

int		ft_print_str(va_list ap, t_data *data)
{
	char	*str;
	int		count;

	count = 0;
	if (data->l_type == 's' && data->point == 0)
	{
		str = va_arg(ap, char *);
		if (!str)
			str = "(null)";
		count = ft_strlen(str);
		if (data->minus == 0)
			print_space(data, str);
		ft_putstr_fd(str, 1);
		if (data->minus == 1)
			print_space(data, str);
	}
	else
		count = ft_print_str2(ap, data);
	return (count > data->width || count == 0 ? count : data->width);
}

int		ft_print_str2(va_list ap, t_data *data)
{
	char	*str;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (data->l_type == 's' && data->point)
	{
		str = va_arg(ap, char *);
		if (!str)
			str = "(null)";
		count = ft_strlen(str);
		i = (data->precision >= 0) ? data->precision : count;
		if (data->minus == 0)
			print_space(data, str);
		(count > i || count == 0) ?
		ft_pcchar(str, i, data) : ft_putstr_fd(str, 1);
		if (data->minus == 1)
			print_space(data, str);
		if (data->precision >= 0 && data->precision - count < 0)
			count = data->precision;
		if (count == 0 && data->width > 0)
			count = data->width;
	}
	return (count > data->width || count == 0 ? count : data->width);
}
