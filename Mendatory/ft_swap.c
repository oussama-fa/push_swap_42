/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:31:18 by oufarah           #+#    #+#             */
/*   Updated: 2025/01/13 19:12:15 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_node **stack)
{
	t_node	*head;
	t_node	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		write(2, "Error\n", 6);
	tmp_val = head->content;
	tmp_index = head->rank;
	head->content = next->content;
	head->rank = next->rank;
	next->content = tmp_val;
	next->rank = tmp_index;
	return (0);
}

int	sa(t_node **stack)
{
	if (ft_swap(stack) == -1)
		return (-1);
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_node **stack)
{
	if (ft_swap(stack) == -1)
		return (-1);
	write(1, "sb\n", 3);
	return (0);
}

int	ss(t_node **a, t_node **b)
{
	if (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2)
		return (-1);
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
	return (0);
}
