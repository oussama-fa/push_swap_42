/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 02:10:54 by oufarah           #+#    #+#             */
/*   Updated: 2025/01/26 16:35:36 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Node
typedef struct s_node
{
	int				content;
	int				rank;
	struct s_node	*next;
}	t_node;

typedef struct s_line
{
	char			*line;
	struct s_line	*next;
}	t_line;

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

// Get_Next_Line
char	*get_next_line(int fd);
char	*ft_strchr(char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);

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

// Checker
int		ft_strcmp(char *s1, char *s2);
int		ft_sorted(t_node *stack);

t_line	*ft_linelast(t_line *lst);
t_line	*ft_linenew(char *line);
void	ft_lineadd_back(t_line **lst, t_line *new);
void	free_line(t_line *head);

#endif