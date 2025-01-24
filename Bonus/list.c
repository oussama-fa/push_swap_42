/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 02:10:46 by oufarah           #+#    #+#             */
/*   Updated: 2025/01/19 03:43:45 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_node	*ft_lstnew(int content)
{
	t_node	*new;

	new = malloc (sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_node *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

void	free_lst(t_node *head)
{
	t_node	*temp;

	if (!head)
		return ;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
