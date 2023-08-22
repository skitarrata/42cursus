/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:23:44 by svalenti          #+#    #+#             */
/*   Updated: 2021/11/10 20:07:51 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define ERR "Error\n"

typedef struct s_swap
{
	long		*veta;
	long		*vetb;
	int			lena;
	int			lenb;
	int			mov;
}				t_swap;

//utils
void	ft_putstr(char *text);
void	ft_init_vet(t_swap *swap, char **argv);
long	*ft_intjoin(t_swap *swap, long const *vet, int dim);
long	*ft_intremove(t_swap *swap, long const *vet, int dim);

//parsing
void	ft_parse_arg(t_swap *swap, int argc, char **argv);

//Check
void	ft_check_num(t_swap *swap, char *argv);
void	ft_check_double(t_swap *swap);
void	ft_check_int(t_swap *swap);
int		ft_check_order(t_swap *swap, int b);
int		ft_check_three(long *vet, int dim);

//push
void	ft_sa(t_swap *swap, int c);
void	ft_sb(t_swap *swap, int c);
void	ft_pa(t_swap *swap);
void	ft_pb(t_swap *swap);
void	ft_ss(t_swap *swap);
void	ft_rr(t_swap *swap);
void	ft_rrr(t_swap *swap);
void	ft_ra(t_swap *swap, int c);
void	ft_rb(t_swap *swap, int c);
void	ft_rra(t_swap *swap, int c);
void	ft_rrb(t_swap *swap, int c);
void	ft_which_combination(t_swap *swap);
void	ft_message(t_swap *swap, char *txt);

//find
long	ft_find_max(t_swap *swap);
long	ft_find_max_a(t_swap *swap);
long	ft_find_min(t_swap *swap);
void	ft_check(t_swap *swap);

//order_stack
void	ft_sort(t_swap *swap, int div);
void	ft_sort_three(t_swap *swap);

//free
void	ft_free_swap(t_swap *swap);
void	ft_error(t_swap *swap, char *text);
#endif