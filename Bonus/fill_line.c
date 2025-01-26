/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:12:56 by oufarah           #+#    #+#             */
/*   Updated: 2025/01/26 16:36:21 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_line	*ft_linelast(t_line *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_line	*ft_linenew(char *line)
{
	t_line	*new;

	new = malloc (sizeof(t_line));
	if (!new)
		return (NULL);
	new->line = line;
	new->next = NULL;
	return (new);
}

void	ft_lineadd_back(t_line **lst, t_line *new)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_linelast(*lst)->next = new;
}

void	free_line(t_line *head)
{
	t_line	*temp;

	if (!head)
		return ;
	while (head)
	{
		free(head ->line);
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
		(1) && (s1++, s2++);
	return (*s1 - *s2);
}
