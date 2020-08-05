# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 17:15:52 by bshang            #+#    #+#              #
#    Updated: 2020/08/04 12:22:17 by bshang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq.a

SRCS = file_read.c file_proc.c matrix_read.c matrix_proc.c square_find_max.c square_is_valid.c utils.c
OBJ = file_read.o file_proc.o matrix_read.o matrix_proc.o square_find_max.o square_is_valid.o utils.o

LIB = $(NAME:.a=.h)
COMPILE = gcc -c -Wall -Werror -Wextra

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(LIB)
	@ar -rcs $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
