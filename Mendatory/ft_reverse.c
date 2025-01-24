/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:55:10 by oufarah           #+#    #+#             */
/*   Updated: 2025/01/13 16:46:46 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack)
{
	ft_reverse(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	ft_reverse(a);
	ft_reverse(b);
	write(1, "rrr\n", 4);
}
