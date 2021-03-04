/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:26:21 by svalenti          #+#    #+#             */
/*   Updated: 2021/02/10 17:26:53 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_data
{
	int				flag;
	int				width;
	char			point;
	int				precision;
	int				lenght;
	int				type;
	char			l_type;
	int				zero;
	int				minus;
	int				sign;
	int				widthmin;
}					t_data;

# define HEX_A		"0123456789abcdef"
# define HEX_AM		"0123456789ABCDEF"

void				ft_datanew(t_data *new);
int					ft_printf(const char *str, ...);
void				ft_check_flag(const char *str, t_data *data);
void				ft_check_type(const char *str, t_data *data);
void				ft_check_width(const char *str, va_list ap, t_data *data);
void				ft_check_precision(const char *str, va_list ap, \
		t_data *data);
int					ft_check_hub(const char *str, va_list ap, \
		t_data *data, int count);
int					ft_count_alpha(va_list ap, t_data *data);
int					ft_control_hub(const char *str, va_list ap, t_data *data);
int					ft_dimu(unsigned long n);
char				*ft_itoau(unsigned long n);
char				*ft_itoa_base(unsigned long long int value, char *base);
void				print_space(t_data *data, char *str);
void				print_space2(t_data *data, char *str);
void				print_space_char(t_data *data);
int					ft_print_str2(va_list ap, t_data *data);
int					ft_print_str(va_list ap, t_data *data);
int					ft_print_char(va_list ap, t_data *data);
void				print_zero(t_data *data, char *str);
char				*ft_conversion_type(va_list ap, t_data *data);
int					ft_print(va_list ap, t_data *data);
void				ft_print_percentage(t_data *data);
void				ft_pcchar(char *str, int i, t_data *data);
char				*ft_not_print_zero(char *str, t_data *data);
void				print_zero_for_flagzero(t_data *data, char *str);
int					print_zero_not_flagzero(t_data *data, int n, int l, int i);
char				*ft_conversion_p(va_list ap, t_data *data);
void				ft_print_space_after(t_data *data, int i, char *str);
int					ft_print_count(int count, t_data *data);
int					ft_print_with_point(t_data *data, int count, int i, \
		char *str);
void				ft_print_not_point(t_data *data, int i, char *str);

#endif
