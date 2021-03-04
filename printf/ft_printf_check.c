/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:29:11 by svalenti          #+#    #+#             */
/*   Updated: 2021/02/09 17:35:05 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag(const char *str, t_data *data)
{
	if (data->precision == 0 && data->width == 0)
	{
		if ((*str) == '-')
			data->minus = 1;
		else if ((*str) == '0')
			data->zero = 1;
		else if (data->zero && data->minus)
			data->zero = 0;
	}
}

void	ft_check_type(const char *str, t_data *data)
{
	if ((*str) == 'd' || (*str) == 'i' || (*str) == 's' ||
			(*str) == 'c' || (*str) == '%')
	{
		data->type = 1;
		data->l_type = *str;
	}
	else if ((*str) == 'x' || (*str) == 'X' || (*str) == 'u' || (*str) == 'p')
	{
		data->type = 1;
		data->l_type = *str;
	}
	return ;
}

void	ft_check_width(const char *str, va_list ap, t_data *data)
{
	if (data->point == 0)
	{
		if ((*str) == '*')
		{
			data->width = va_arg(ap, int);
			if (data->width < 0)
			{
				data->minus = 1;
				data->widthmin = 1;
				data->width *= -1;
			}
		}
		if ((*str) >= '0' && (*str) <= '9')
			data->width = (data->width * 10) + (*str - '0');
	}
}

void	ft_check_precision(const char *str, va_list ap, t_data *data)
{
	if ((*str) == '.')
	{
		data->point = 1;
		str++;
		if (!((*str) >= '0' && (*str) <= '9') && (*str) != '*')
			data->precision = 0;
		if ((*str) == '*')
		{
			data->precision = va_arg(ap, int);
			if (data->width < 0)
			{
				data->precision = 0;
				data->point = 0;
			}
		}
		while ((*str) >= '0' && (*str) <= '9')
		{
			data->precision = (data->precision * 10) + (*str - '0');
			str++;
		}
	}
}

int		ft_control_hub(const char *str, va_list ap, t_data *data)
{
	int				count;
	unsigned int	alpha;

	alpha = 0;
	while (*str)
	{
		count = 1;
		ft_datanew(data);
		if (*str == '%')
		{
			++str;
			while (*str && count)
			{
				count = ft_check_hub(str, ap, data, count);
				str++;
			}
			alpha += ft_count_alpha(ap, data);
		}
		else
		{
			ft_putchar_fd(*str++, 1);
			alpha++;
		}
	}
	return (alpha);
}
