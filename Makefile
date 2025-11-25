# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 12:24:40 by dmota-ri          #+#    #+#              #
#    Updated: 2025/11/25 18:27:01 by dmota-ri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap_main.c\
	push_swap_operations_dup.c\
	push_swap_operations.c\
	push_swap_push_to_side_sort.c\
	push_swap_utils.c\
	push_swap_rotate_to_side.c

OBJ = $(SRC:.c=.o)

#BONUS = ft_lists_1_bonus.c ft_lists_2_bonus.c

#B_OBJ = $(BONUS:.c=.o)

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.h
LIBFT_NAME = $(LIBFT_DIR)libft.a

LIB = push_swap.h

CFLAGS = -Wall -Wextra -Werror -DNO_MAIN
CC = cc $(CFLAGS)

RM = rm -f
AR = ar rcs

all: $(NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT_NAME) $(OBJ) $(LIB)
	$(CC) -I $(LIBFT_DIR) -I . $(OBJ) $(LIBFT_NAME) -o $(NAME)

%.o: %.c $(LIB)
	$(CC) -I $(LIBFT_DIR) -I . -c $< -o $@

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
