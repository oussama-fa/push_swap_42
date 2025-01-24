# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 09:56:30 by oufarah           #+#    #+#              #
#    Updated: 2025/01/24 16:26:16 by oufarah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_2 = checker

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

INCS = Mendatory/push_swap.h

INCS_B = Bonus/push_swap_bonus.h

SRC =  Mendatory/ft_atoi.c Mendatory/ft_split.c Mendatory/list.c Mendatory/pars.c \
		Mendatory/push_swap.c Mendatory/ft_push.c Mendatory/ft_swap.c Mendatory/ft_rotate.c Mendatory/ft_reverse.c\
		Mendatory/sorting_utils.c Mendatory/sorting.c

SRC_B = Bonus/ft_atoi.c Bonus/ft_split.c Bonus/list.c Bonus/pars.c \
		Bonus/checker.c Bonus/ft_push.c Bonus/ft_swap.c Bonus/ft_rotate.c Bonus/ft_reverse.c \
		Bonus/get_next_line.c Bonus/get_next_line_utils.c Bonus/fill_line.c

OBJS = $(SRC:.c=.o)

OBJS_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME) :$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(INCS) $(INCS_B)
	$(CC) $(FLAGS) -c $< -o $@

bonus : $(NAME_2)

$(NAME_2) :$(OBJS_B)
	$(CC) $(FLAGS) $(OBJS_B) -o $(NAME_2)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME) $(NAME_2)

re: fclean all

.PHONY : clean