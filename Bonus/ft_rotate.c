/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 02:09:38 by oufarah           #+#    #+#             */
/*   Updated: 2025/01/24 16:07:49 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}

void	rb(t_node **stack)
{
	if (ft_lstsize(*stack) < 2 || !*stack)
		return ;
	ft_rotate(stack);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
