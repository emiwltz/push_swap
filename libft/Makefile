# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: emi <emi@student.42.fr>                    +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2024/01/01 00:00:00 by emi               #+#    #+#             #
#    Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isdigit.c \
       ft_strlen.c \
       ft_strcmp.c \
       ft_strchr.c \
       ft_strdup.c \
       ft_mem.c \
       ft_atoi.c \
       ft_itoa.c \
       ft_split.c \
       ft_put.c \
       ft_lst.c \
       ft_lst2.c \
       ft_substr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
