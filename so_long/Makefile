# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttreichl <ttreichl@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 15:28:18 by ttreichl          #+#    #+#              #
#    Updated: 2024/01/31 19:34:50 by ttreichl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
MLX			= -lmlx -lXext -lX11


INCLUDE		=	-I ./includes -I 
SOURCE		=	./Sources/

############################################################################
############################################################################
MAP 		=		$(addprefix map/, \
					map.c map_init.c map_cheker.c map_utils.c \
					)

WINDOW 		=		$(addprefix window/, \
					window_validation.c \
					)

A_SRC 		=		$(addprefix $(SOURCE), \
					$(MAP) $(WINDOW) \
					endgame.c image.c \
					so_long.c \
					)					
############################################################################
############################################################################					

SRC = $(A_SRC)

OBJ = $(SRC:%.c=%.o)

############################################################################
############################################################################

all:	$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -O2 -c $< -o $(<:%.c=%.o)

$(NAME): $(OBJ)
		make -C ./Libft
		$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)
	
clean:
		rm -rf $(OBJ)
		rm -rf ./a.out
		make clean -C ./Libft

fclean: clean
		rm -rf $(NAME)
		make fclean -C ./Libft

re: fclean all

.PHONY: all bonus clean fclean re