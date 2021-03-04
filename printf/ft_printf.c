/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:26:34 by svalenti          #+#    #+#             */
/*   Updated: 2021/02/09 19:57:03 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_count(int count, t_data *data)
{
	if (data->precision >= 0 && count < data->precision)
	{
		count = data->precision;
		if (data->sign && (data->l_type == 'd' || data->l_type == 'i'))
			count++;
	}
	return (count);
}

void	ft_datanew(t_data *new)
{
	new->flag = 0;
	new->width = 0;
	new->point = 0;
	new->precision = 0;
	new->lenght = 0;
	new->type = 0;
	new->l_type = 0;
	new->zero = 0;
	new->minus = 0;
	new->sign = 0;
	new->widthmin = 0;
}

int		ft_printf(const char *str, ...)
{
	int		ret;
	va_list	ap;
	t_data	data;

	ret = 0;
	ft_datanew(&data);
	va_start(ap, str);
	ret = ft_control_hub(str, ap, &data);
	va_end(ap);
	return (ret);
}
