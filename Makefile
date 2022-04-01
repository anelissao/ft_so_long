# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 11:15:03 by aelissao          #+#    #+#              #
#    Updated: 2022/08/02 16:07:36 by aelissao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	so_long

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit

SRC			=	util.c					\
				utils2.c				\
				util3.c					\
				get_next_line.c			\
				get_next_line_utils.c	\
				so_long.c				\
				moves.c					\
				keys.c					\
				ft_split.c				\
				ft_print_hex.c			\
				ft_print_string.c		\
				ft_print_u.c			\
				ft_printf.c				\
				ft_putchar_count.c		\
				ft_putnbr.c				

HEADER		=	so_long.h ft_printf.h

OBJ			=	$(SRC:.c=.o)


all			:	$(NAME)

$(NAME)		:	$(OBJ)
				$(CC) $(SRC) $(MLX_FLAGS) -o $(NAME) -g

%.o			:	%.c $(HEADER)
				$(CC) $(FLAGS) -Imlx -c $< -o $@
	
clean 		:
				rm -f $(OBJ)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re