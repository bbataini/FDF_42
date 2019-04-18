# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbataini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 16:24:23 by bbataini          #+#    #+#              #
#    Updated: 2019/04/18 20:10:20 by bbataini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_LIST = main.c \
			parser.c \
			isometric.c \
			size.c \
			trace.c \
			newimg.c \
			text.c \
			parallel.c \

LIB = libft/libft.a \
	  minilibx_macos/libmlx.a \

CLIB = libft/ \
	   minilibx_macos/ \

INC = fdf.h \

FAFO = -framework AppKit -framework OpenGL

all: $(NAME)
	make -C libft/
	make -C minilibx_macos/
	$(CC) $(CFLAGS) $(SRCS_LIST) $(LIB) -I $(INC) $(FAFO)
	mv a.out fdf

clean:
	make -C libft/ clean
	make -C minilibx_macos/ clean

fclean: clean
		make fclean -C libft/
		rm -f fdf

re: fclean all
