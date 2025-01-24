/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 09:37:46 by oufarah           #+#    #+#             */
/*   Updated: 2025/01/11 13:51:08 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_validity(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] != '\0')
		return (0);
	return (1);
}

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	msg_exit(t_vars *vars)
{
	free_arr(vars->tmp);
	free_lst(vars->head);
	write(2, "Error\n", 6);
}

int	check_same_number(t_vars *vars)
{
	while (vars->temp)
	{
		if ((vars->temp)->content == vars->ret)
			return (0);
		vars->temp = (vars->temp)->next;
	}
	vars->new_node = ft_lstnew(vars->ret);
	if (!vars->new_node)
		return (0);
	ft_lstadd_back(&vars->head, vars->new_node);
	return (1);
}

t_node	*parsing(int ac, char **av)
{
	t_vars	vars;

	(1) && (vars.i = 0, vars.head = NULL);
	if (!av[1])
		return (write(2, "Error\n", 6), NULL);
	while (++vars.i < ac)
	{
		vars.tmp = ft_split(av[vars.i], ' ');
		if (!vars.tmp || !*vars.tmp)
			return (msg_exit(&vars), NULL);
		vars.j = -1;
		while (vars.tmp[++vars.j])
		{
			if (!check_validity(vars.tmp[vars.j]))
				return (msg_exit(&vars), NULL);
			vars.ret = ft_atoi(vars.tmp[vars.j]);
			if (vars.ret == 2147483648)
				return (msg_exit(&vars), NULL);
			vars.temp = vars.head;
			if (!check_same_number(&vars))
				return (msg_exit(&vars), NULL);
		}
		free_arr(vars.tmp);
	}
	return (vars.head);
}
