/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:58:12 by oufarah           #+#    #+#             */
/*   Updated: 2025/01/12 16:39:43 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || ft_lstsize(*stack) < 2 || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_node **stack)
{
	if (ft_lstsize(*stack) < 2 || !*stack)
		return ;
	ft_rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack)
{
	if (ft_lstsize(*stack) < 2 || !*stack)
		return ;
	ft_rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return ;
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}
