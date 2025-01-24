/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:26:03 by oufarah           #+#    #+#             */
/*   Updated: 2025/01/19 02:15:55 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_bigger(t_node *stack, int num)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->content < num)
			count++;
		stack = stack->next;
	}
	return (count);
}

void	rank_them(t_node **stack)
{
	t_node	*temp;

	temp = *stack;
	while (temp)
	{
		temp->rank = count_bigger(*stack, temp->content);
		temp = temp->next;
	}
}

void	push_to_b(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = ft_lstsize(*stack_a);
	if (j < 150)
		j /= 7;
	else
		j /= 15;
	while (*stack_a)
	{
		if ((*stack_a)->rank <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->rank <= i + j)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

int	get_index(t_node *stack, int rank)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->rank == rank)
			return (index);
		index++;
		stack = stack->next;
	}
	return (index);
}

void	push_to_a(t_node **stack_a, t_node **stack_b)
{
	int	size;

	while (*stack_b)
	{
		size = ft_lstsize(*stack_b);
		if (get_index(*stack_b, size - 1) > size / 2)
		{
			while ((*stack_b)->rank != size - 1)
				rrb(stack_b);
		}
		else
		{
			while ((*stack_b)->rank != size - 1)
				rb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}
