/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 09:37:52 by oufarah           #+#    #+#             */
/*   Updated: 2025/01/19 05:11:09 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

// Node
typedef struct s_node
{
	int				content;
	int				rank;
	struct s_node	*next;
}	t_node;

// Parsing
typedef struct s_vars
{
	int		i;
	int		j;
	long	ret;
	char	**tmp;
	t_node	*temp;
	t_node	*head;
	t_node	*new_node;
}	t_vars;

t_node	*parsing(int ac, char **av);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);

// Linked Lists
void	ft_lstadd_back(t_node **lst, t_node *new);
void	free_lst(t_node *head);
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstnew(int content);
int		ft_lstsize(t_node *lst);

// Swap
int		ft_swap(t_node **stack);
int		sa(t_node **stack);
int		sb(t_node **stack);
int		ss(t_node **a, t_node **b);

// Push
void	ft_push(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);

// Rotate
void	ft_rotate(t_node **stack);
void	ra(t_node **stack);
void	rb(t_node **stack);
void	rr(t_node **stack_a, t_node **stack_b);

// Reverse
void	ft_reverse(t_node **stack);
void	rra(t_node **stack);
void	rrb(t_node **stack);
void	rrr(t_node **a, t_node **b);

// Sorting
int		ft_sorted(t_node *stack);
int		max_in_stack(t_node *stack);
int		min_in_stack(t_node *stack);
int		get_index(t_node *stack, int rank);
int		count_bigger(t_node *stack, int num);
void	sort_it(t_node **stack_a, t_node **stack_b);
void	rank_them(t_node **stack);
void	sort_3(t_node **stack);
void	sort_4(t_node **stack_a, t_node **stack_b);
void	sort_5(t_node **stack_a, t_node **stack_b);
void	push_to_a(t_node **stack_a, t_node **stack_b);
void	push_to_b(t_node **stack_a, t_node **stack_b);

#endif