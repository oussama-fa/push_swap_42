/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:54:35 by oufarah           #+#    #+#             */
/*   Updated: 2025/01/16 15:43:18 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_node **a, t_node **b)
{
	t_node	*temp;

	temp = *a;
	if (!*b)
	{
		*a = (*a)->next;
		*b = temp;
		(*b)->next = NULL;
	}
	else
	{
		temp = *a;
		*a = temp->next;
		temp->next = *b;
		*b = temp;
	}
}

void	pb(t_node **a, t_node **b)
{
	if (!*a)
		return ;
	ft_push(a, b);
	write(1, "pb\n", 3);
}

void	pa(t_node **a, t_node **b)
{
	if (!*b)
		return ;
	ft_push(b, a);
	write(1, "pa\n", 3);
}
