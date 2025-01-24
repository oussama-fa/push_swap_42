/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 09:37:56 by oufarah           #+#    #+#             */
/*   Updated: 2025/01/24 15:55:47 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_node *stack)
{
	while (stack)
	{
		if (stack->next && stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_it(t_node **stack_a, t_node **stack_b)
{
	int		size;

	rank_them(stack_a);
	size = ft_lstsize(*stack_a);
	if (size > 5)
	{
		push_to_b(stack_a, stack_b);
		push_to_a(stack_a, stack_b);
	}
}

void	sorting(t_node **stack_a, t_node **stack_b)
{
	size_t	size;

	size = ft_lstsize(*stack_a);
	if (size == 1)
		return ;
	else if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
		sort_it(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = parsing(ac, av);
	stack_b = NULL;
	if (!ft_sorted(stack_a))
		sorting(&stack_a, &stack_b);
	free_lst(stack_a);
	free_lst(stack_b);
	return (0);
}
