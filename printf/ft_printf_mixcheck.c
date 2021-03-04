/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mixcheck.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:50:23 by svalenti          #+#    #+#             */
/*   Updated: 2021/02/10 18:09:39 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_not_print_zero(char *str, t_data *data)
{
	if (*str == '0' && !data->precision && data->point && data->l_type == 'p')
		str = "0x";
	else if (*str == '0' && !data->precision && data->point)
		str = "";
	return (str);
}

void	ft_print_space_after(t_data *data, int i, char *str)
{
	print_zero(data, str);
	ft_putstr_fd(str, 1);
	if (data->width > data->precision)
		while (i-- > 0)
			ft_putchar_fd(' ', 1);
}

void	print_zero_for_flagzero(t_data *data, char *str)
{
	int i;
	int l;

	l = ft_strlen(str);
	i = data->sign ? -1 : 0;
	if (data->width > data->precision && data->precision <= l && data->sign)
		i += data->width - ft_strlen(str) + 1;
	else if (data->width > data->precision && data->precision < l)
		i += data->width - ft_strlen(str);
	else if (data->width > data->precision)
		i += data->width - data->precision;
	if (data->sign && data->precision == l)
		i--;
	while (i-- > 0)
		ft_putchar_fd(' ', 1);
}

int		print_zero_not_flagzero(t_data *data, int n, int l, int i)
{
	if (l > data->precision && data->zero && data->width > data->precision &&
	data->point && !data->sign && (data->l_type == 'd' || data->l_type == 'i'))
		i += data->width - l;
	else if (data->width > data->precision && data->precision && !data->sign &&
	data->l_type != 'x' && data->l_type != 'u' && data->l_type != 'X')
		i += data->width - data->precision;
	else if (data->width > data->precision && data->zero && data->point &&
	data->precision && l <= data->precision && data->sign &&
	(data->l_type == 'd' || data->l_type == 'i'))
		i += data->width - data->precision;
	else if (data->width > data->precision && l >= data->precision &&
	data->sign)
		i += data->width - l + 1;
	else if (l > data->precision && !data->sign)
		i += data->width - l;
	else if (data->width > data->precision)
		i += data->width - data->precision;
	if (data->width < data->precision)
		n = data->precision - l;
	(data->sign && (n != i)) ? (n -= i + 1) : (n -= i);
	while (i-- > 0)
		ft_putchar_fd(' ', 1);
	return (n);
}

char	*ft_conversion_p(va_list ap, t_data *data)
{
	char					*str;
	unsigned long long int	nbr;

	str = NULL;
	nbr = va_arg(ap, unsigned long long int);
	str = ft_itoa_base(nbr, HEX_A);
	if (data->precision > data->width)
	{
		ft_putstr_fd("0x", 1);
		free(str);
		return (str);
	}
	str = ft_strjoin("0x", str);
	free(str);
	return (str);
}
