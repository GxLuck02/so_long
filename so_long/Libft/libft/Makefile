# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttreichl <ttreichl@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 16:04:41 by ttreichl          #+#    #+#              #
#    Updated: 2024/02/01 15:48:08 by ttreichl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libft.a

CC						= gcc
RM						= rm -rf
CFLAGS			= -Wall -Wextra -Werror

SRCS			=	ft_memcmp.c ft_strdup.c ft_split.c ft_strlcpy.c ft_isalnum.c ft_putnbr_fd.c \
					ft_memset.c ft_memmove.c ft_strjoin.c ft_strchr.c ft_calloc.c \
					ft_isdigit.c ft_isascii.c ft_isprint.c ft_strlcat.c ft_striteri.c \
					ft_putstr_fd.c ft_itoa.c ft_bzero.c ft_putendl_fd.c ft_memcpy.c \
					ft_memchr.c ft_isalpha.c ft_strlen.c ft_toupper.c ft_tolower.c \
					ft_substr.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
					ft_strtrim.c ft_atoi.c ft_putchar_fd.c ./get_next_line/get_next_line.c

B_SRC			= 	ft_lstnew.c ft_lstsize.c ft_lstadd_front.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
					ft_lstmap.c

OBJS			=	$(SRCS:.c=.o)

B_OBJS			=	$(B_SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all:			$(NAME) $(BONUS)

$(NAME): 		$(OBJS)
				ar rcs $(NAME)	$(OBJS)

bonus:			$(B_OBJS)
				ar rcs $(NAME)	$(B_OBJS)

clean:
				$(RM) $(OBJS) $(B_OBJS)

fclean:			clean
						$(RM) $(NAME)

re:				fclean all

.PHONY:			all bonus clean fclean re