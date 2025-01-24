/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:14:04 by oufarah           #+#    #+#             */
/*   Updated: 2025/01/16 15:45:59 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_in_stack(t_node *stack)
{
	int	max;

	max = stack->content;
	while (stack)
	{
		if (max < stack->content)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

int	min_in_stack(t_node *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (min > stack->content)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

void	sort_3(t_node **stack)
{
	int	max;

	max = max_in_stack(*stack);
	if ((*stack)->content == max)
		ra(stack);
	else if ((*stack)->next->content == max)
		rra(stack);
	if ((*stack)->content > (*stack)->next->content)
		sa(stack);
}

void	sort_4(t_node **stack_a, t_node **stack_b)
{
	int	min;

	min = min_in_stack(*stack_a);
	while ((*stack_a)->content != min)
	{
		ra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_a);
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int	min;

	min = min_in_stack(*stack_a);
	while ((*stack_a)->content != min)
	{
		ra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_a);
}
