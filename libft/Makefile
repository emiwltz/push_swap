# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 14:11:35 by alemyre           #+#    #+#              #
#    Updated: 2025/11/24 13:55:03 by alemyre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	libft.a

CC=		cc
CFLAGS=	-Wall -Wextra -Werror -MMD -MP
AR=		ar rcs

SRCS=	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

OBJS=	$(addprefix $(BUILD_DIR), $(SRCS:.c=.o))
DEPS=	$(OBJS:.o=.d)

SRCS_B=	ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJS_B=	$(addprefix $(BUILD_DIR), $(SRCS_B:.c=.o))
DEPS_B= $(OBJS_B:.o=.d)

BUILD_DIR = .build/

BONUS_N=.bonus

all: $(NAME)

$(NAME): $(OBJS) 
	$(AR) $(NAME) $(OBJS)

bonus: $(BONUS_N)

$(BONUS_N): $(OBJS) $(OBJS_B)
	$(AR) $(NAME) $(OBJS_B)
	touch $(BONUS_N)

-include $(DEPS) $(DEPS_B)

$(BUILD_DIR)%.o: %.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_B) $(DEPS) $(DEPS_B)
	rm -f $(BONUS_N)
	rm -fd $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

re_bonus: re bonus

.PHONY: all clean fclean re bonus re_bonus