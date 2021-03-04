/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:07:52 by svalenti          #+#    #+#             */
/*   Updated: 2021/02/11 15:04:46 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_zero(t_data *data, char *str)
{
	int n;
	int i;
	int l;

	l = ft_strlen(str);
	i = data->sign ? -1 : 0;
	n = data->zero ? (data->width - l) : (data->precision - l);
	if (n < 0 && data->precision < data->width &&
			l > data->precision && data->sign == 0)
		n = 0;
	if (data->width > data->precision && data->minus == 0 && data->zero == 0)
		print_zero_for_flagzero(data, str);
	else if (data->zero && data->precision >= 0 &&
			data->point && data->widthmin == 0)
		n = print_zero_not_flagzero(data, n, l, i);
	if (*str == '-')
	{
		ft_putchar_fd('-', 1);
		data->precision > 0 ? n++ : n;
	}
	if (n <= 0 || (data->widthmin && data->zero))
		return ;
	if (n > 0 && (l <= data->precision || !data->point))
		while (n-- > 0)
			ft_putchar_fd('0', 1);
}

char	*ft_conversion_type(va_list ap, t_data *data)
{
	char			*str;
	char			*hex;
	unsigned int	nbr;

	str = NULL;
	nbr = va_arg(ap, unsigned int);
	if ((unsigned long long)nbr < 0 &&
			(data->l_type == 'u' || data->l_type == 'x' || data->l_type == 'X'))
		data->sign = 1;
	else if ((int)nbr < 0 && (data->l_type == 'i' || data->l_type == 'd'))
		data->sign = 1;
	if (data->l_type == 'd' || data->l_type == 'i')
		str = ft_itoa((int)nbr);
	else if (data->l_type == 'u')
		str = ft_itoau((unsigned int)nbr);
	else if (data->l_type == 'x' || data->l_type == 'X')
	{
		hex = (data->l_type == 'X') ? HEX_AM : HEX_A;
		str = ft_itoa_base((unsigned long long)nbr, hex);
	}
	free(str);
	return (str);
}

int		ft_print_with_point(t_data *data, int count, int i, char *str)
{
	if (data->minus == 0)
	{
		print_zero(data, str);
		if (*str == '-')
			str++;
		ft_putstr_fd(str, 1);
		count = ft_print_count(count, data);
	}
	else if (data->minus == 1)
	{
		i = (data->sign && data->l_type != 'u' &&
		data->l_type != 'x' && data->l_type != 'X') ? 1 : 0;
		data->precision >= count ? (i = data->width - data->precision) :
		(i += data->width - count);
		if (*str == '-')
		{
			ft_putchar_fd('-', 1);
			i--;
			str++;
		}
		ft_print_space_after(data, i, str);
		count = ft_print_count(count, data);
	}
	return (count);
}

void	ft_print_not_point(t_data *data, int i, char *str)
{
	if (data->minus == 0)
	{
		print_zero(data, str);
		if (*str == '-')
			str++;
		ft_putstr_fd(str, 1);
	}
	else if (data->minus == 1)
	{
		i = data->sign ? 1 : 0;
		if (data->l_type == 'p' && data->minus && data->sign)
			i--;
		i += data->width - ft_strlen(str);
		if (*str == '-')
		{
			ft_putchar_fd('-', 1);
			i--;
			str++;
		}
		ft_print_space_after(data, i, str);
	}
}

int		ft_print(va_list ap, t_data *data)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	count = 0;
	if (data->l_type == 'd' || data->l_type == 'i' || data->l_type == 'p' ||
	data->l_type == 'u' || data->l_type == 'x' || data->l_type == 'X')
	{
		str = (data->l_type != 'p') ? ft_conversion_type(ap, data) :
			ft_conversion_p(ap, data);
		str = ft_not_print_zero(str, data);
		count = ft_strlen(str);
		if (data->point == 0)
			ft_print_not_point(data, i, str);
		else if (data->point)
			count = ft_print_with_point(data, count, i, str);
		if (data->precision > data->width && data->l_type == 'p')
			count += 2;
		if (count < data->width)
			count = data->width;
	}
	return (count);
}
