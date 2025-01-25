/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 02:12:44 by oufarah           #+#    #+#             */
/*   Updated: 2025/01/24 17:17:40 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	apply(t_node **stack_a, t_node **stack_b, char *comp)
{
	if (!ft_strcmp(comp, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(comp, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(comp, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(comp, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(comp, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(comp, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(comp, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(comp, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(comp, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(comp, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(comp, "rrr\n"))
		rrr(stack_a, stack_b);
}

int	check_line(char *line)
{
	char	*lines[12] = {"pa\n", "pb\n", "sa\n", "sb\n", "ss\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", NULL};
	int		i;

	i = 0;
	while (lines[i])
		if (!ft_strcmp(lines[i++], line))
			return (0);
	return (1);
}

t_line	*get_lines(void)
{
	t_line	*lines;
	char	*temp;

	lines = NULL;
	while (1)
	{
		temp = get_next_line(0);
		if (!temp)
			break ;
		if (check_line(temp))
		{
			free_line(lines);
			write(2, "Error\n", 6);
			exit(1);
		}
		ft_lineadd_back(&lines, ft_linenew(temp));
	}
	return (lines);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_line	*lines;

	if (ac == 1)
		return (0);
	if (av[1][0] == '\0')
		return (write(2, "Error\n", 6), 1);
	lines = get_lines();
	stack_a = parsing(ac, av);
	stack_b = NULL;
	while (lines)
	{
		apply(&stack_a, &stack_b, lines->line);
		lines = lines -> next;
	}
	free_line(lines);
	if (ft_sorted(stack_a) && ft_lstsize(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	free_lst(stack_a);
	free_lst(stack_b);
	return (0);
}
