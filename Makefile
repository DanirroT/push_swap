# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmota-ri <dmota-ri@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 12:24:40 by dmota-ri          #+#    #+#              #
#    Updated: 2025/12/02 18:01:06 by dmota-ri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap_main.c\
	push_swap_operations_dup.c\
	push_swap_operations.c\
	push_swap_push_to_side_sort.c\
	push_swap_utils.c\
	push_swap_rotate_to_side.c\
	push_swap_simple_solve.c\
	push_swap_push_to_side_sort_stop.c\
	push_swap_radix.c

OBJ = $(SRC:.c=.o)

#BONUS = ft_lists_1_bonus.c ft_lists_2_bonus.c

#B_OBJ = $(BONUS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.h
LIBFT_NAME = $(LIBFT_DIR)/libft.a

INC = push_swap.h

CFLAGS = -Wall -Wextra -Werror -DNO_MAIN
CC = cc $(CFLAGS)

RM = rm -f

all: $(NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT_NAME) $(OBJ) $(INC)
	$(CC) -I $(LIBFT_DIR) -I . $(OBJ) $(LIBFT_NAME) -o $(NAME)

%.o: %.c $(INC)
	$(CC) -I $(LIBFT_DIR) -I . -c $< -o $@
	echo 123

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

#bonus: $(B_OBJ) $(NAME)
#	$(CC) -I $(LIBFT_DIR) -I . $(OBJ) -o $(B_OBJ)
#	ranlib $(NAME) 
