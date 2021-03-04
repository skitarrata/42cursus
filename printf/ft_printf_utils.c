/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:25:59 by svalenti          #+#    #+#             */
/*   Updated: 2021/02/09 17:35:15 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dimu(unsigned long n)
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

char	*ft_itoau(unsigned long n)
{
	unsigned long	nb;
	char			*str;
	size_t			i;

	nb = n;
	nb = nb > 0 ? nb : -nb;
	i = ft_dimu(n);
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

char	*ft_itoa_base(unsigned long long int value, char *base)
{
	unsigned long long int	count;
	unsigned long int		tmp;
	char					*res;
	unsigned int			base_length;

	base_length = ft_strlen(base);
	count = (value < 0) ? 2 : 1;
	tmp = (value < 0) ? -value : value;
	while (tmp >= base_length && (tmp /= base_length))
		++count;
	tmp = (value < 0) ? -value : value;
	if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	if (value < 0)
		res[0] = '-';
	res[count] = '\0';
	while (tmp >= base_length)
	{
		--count;
		res[count] = base[tmp % base_length];
		tmp /= base_length;
	}
	res[--count] = base[tmp % base_length];
	return (res);
}

int		ft_check_hub(const char *str, va_list ap, t_data *data, int count)
{
	ft_check_flag(str, data);
	ft_check_width(str, ap, data);
	ft_check_precision(str, ap, data);
	ft_check_type(str, data);
	if (data->l_type)
		count = 0;
	return (count);
}

int		ft_count_alpha(va_list ap, t_data *data)
{
	unsigned int alpha;

	alpha = 0;
	alpha += ft_print_char(ap, data);
	alpha += ft_print_str(ap, data);
	alpha += ft_print(ap, data);
	return (alpha);
}
