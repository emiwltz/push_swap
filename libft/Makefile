<<<<<<< HEAD
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
=======
NAME	 	= libft.a

CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra -MMD -MP
AR 			= ar rcs

BUILD_DIR 	= .build/
SRC_DIR		= src/
GNL_DIR		= get_next_line/
PRNTF_DIR	= ft_printf/

SRCS_SRC	 	= $(addprefix $(SRC_DIR), ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strdup.c \
			ft_strchr.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstadd_back_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstsize_bonus.c)

SRCS_GNL		= $(addprefix $(GNL_DIR), get_next_line.c \
			get_next_line_utils.c)

SRCS_PRNTF		= $(addprefix $(PRNTF_DIR), ft_printf.c \
			ft_printf_char.c \
			ft_printf_hexa_low.c \
			ft_printf_hexa_up.c \
			ft_printf_int.c \
			ft_printf_ptr.c \
			ft_printf_string.c \
			ft_printf_unsigned.c)

OBJS_SRCS 	= $(addprefix $(BUILD_DIR), $(SRCS_SRC:.c=.o))
OBJS_GNL 	= $(addprefix $(BUILD_DIR), $(SRCS_GNL:.c=.o))
OBJS_PRNTF 	= $(addprefix $(BUILD_DIR), $(SRCS_PRNTF:.c=.o))

DEPS_SRCS 	= $(OBJS_SRCS:.o=.d)
DEPS_GNL 	= $(OBJS_GNL:.o=.d)
DEPS_PRNTF 	= $(OBJS_PRNTF:.o=.d)

all: $(NAME)

$(NAME): $(OBJS_SRCS) $(OBJS_GNL) $(OBJS_PRNTF)
	$(AR) $@ $^

$(BUILD_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SRCS) $(DEPS_SRCS) $(OBJS_GNL) $(DEPS_GNL) $(OBJS_PRNTF) $(DEPS_PRNTF)
	rm -fd $(BUILD_DIR)$(SRC_DIR) $(BUILD_DIR)$(GNL_DIR) $(BUILD_DIR)$(PRNTF_DIR) 

fclean:	clean
>>>>>>> b87d02cfca3a0c3f6005c3abae003012a7d56c66
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
<<<<<<< HEAD
=======

-include $(DEPS_SRCS) $(DEPS_GNL) $(DEPS_PRNTF)
>>>>>>> b87d02cfca3a0c3f6005c3abae003012a7d56c66
