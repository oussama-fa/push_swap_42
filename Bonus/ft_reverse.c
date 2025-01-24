/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 02:09:35 by oufarah           #+#    #+#             */
/*   Updated: 2025/01/19 03:41:02 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_reverse(t_node **stack)
{
	t_node	*last;
	t_node	*second;

	last = ft_lstlast(*stack);
	second = *stack;
	if (!*stack || !(*stack)->next)
		return ;
	while (second->next != last)
		second = second->next;
	second->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **stack)
{
	ft_reverse(stack);
}

void	rrb(t_node **stack)
{
	ft_reverse(stack);
}

void	rrr(t_node **a, t_node **b)
{
	ft_reverse(a);
	ft_reverse(b);
}
