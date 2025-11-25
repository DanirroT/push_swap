# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 12:24:40 by dmota-ri          #+#    #+#              #
#    Updated: 2025/11/19 14:13:50 by dmota-ri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_change.c\
	ft_is_x.c\
	ft_memory_1.c\
	ft_memory_2.c\
	ft_str_2_split.c\
	ft_str_2_trim.c\
	ft_str_11.c\
	ft_str_12.c\
	ft_str_21.c\
	ft_str_22.c\
	ft_lists_1_bonus.c\
	ft_lists_2_bonus.c\
	ft_printf.c\
	ft_printf_utils.c

OBJ = $(SRC:.c=.o)

LIB = libft.h ft_printf.h

CFLAGS = -Wall -Wextra -Werror -DNO_MAIN
CC = cc $(CFLAGS)

RM = rm -f
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME) 

%.o: %.c $(LIB)
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#bonus: $(B_OBJ) $(NAME)
#	$(AR) $(NAME) $(OBJ) $(B_OBJ)
#	ranlib $(NAME) 