# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 15:12:11 by cmiran            #+#    #+#              #
#    Updated: 2018/09/27 16:19:03 by cmiran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./include/\
	  /usr/X11/inc\
	  ./libft/includes/

NAME = fdf

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror

SRC_NAME = main.c\
	   parse.c\
	   populate.c\
	   draw.c\
	   key.c\
	   error.c

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))
INC = $(addprefix -I, $(INC_DIR))

LIB = -L /usr/X11/lib -L ./libft -lft -lmlx

all: $(NAME)

$(NAME): obj $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@ -framework OpenGL -framework AppKit

obj:
	mkdir obj

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INC)

clean:
	make clean -C ./libft
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
