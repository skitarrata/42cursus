/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:53:06 by svalenti          #+#    #+#             */
/*   Updated: 2021/01/15 19:01:09 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *n;

	if (!(n = (t_list *)malloc(sizeof(t_list))))
		return (0);
	n->content = content;
	n->next = NULL;
	return (n);
}
