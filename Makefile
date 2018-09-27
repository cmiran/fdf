
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/26 19:39:07 by cmiran            #+#    #+#              #
#    Updated: 2018/09/27 12:27:09 by cmiran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=		gcc
CFLAGS=		-Wall -Werror -Wextra
NAME=		fdf


LIB_DIR=	./libft
LIB=		./libft/libft.a
LIB_LINK=	 -L $(LIB_DIR) -lft -L $(MLX_DIR)/lib -lmlx

MLX_DIR=	/usr/X11/

INC_DIR=	./include
INCS=		 -I $(INC_DIR) -I $(LIB_DIR) -I $(MLX_DIR)/include

SRC_DIR=	./src
SRC=		main.c\
		parse.c\
		populate.c\
		draw.c\
		key.c\
		error.c

OBJ_DIR=	./obj
OBJS=		$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): obj $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_LINK) -o $@ -framework OpenGL -framework AppKit

obj:
	mkdir -p obj

$(LIB):
	make -C ./libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCS)

clean:
	make clean -C ./libft
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
