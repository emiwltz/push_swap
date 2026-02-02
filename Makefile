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

NAME = push_swap
CHECKER = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INC_DIR = includes
SRC_DIR = src
OBJ_DIR = obj
BONUS_DIR = src_bonus

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/stack.c \
       $(SRC_DIR)/stack_utils.c \
       $(SRC_DIR)/ops_swap.c \
       $(SRC_DIR)/ops_push.c \
       $(SRC_DIR)/ops_rotate.c \
       $(SRC_DIR)/ops_reverse_rotate.c \
       $(SRC_DIR)/parsing.c \
       $(SRC_DIR)/parsing_args.c \
       $(SRC_DIR)/utils.c \
       $(SRC_DIR)/utils2.c \
       $(SRC_DIR)/disorder.c \
       $(SRC_DIR)/sort_small.c \
       $(SRC_DIR)/sort_simple.c \
       $(SRC_DIR)/sort_medium.c \
       $(SRC_DIR)/sort_complex.c \
       $(SRC_DIR)/sort_adaptive.c \
       $(SRC_DIR)/data.c \
       $(SRC_DIR)/benchmark.c

SRCS_BONUS = $(BONUS_DIR)/checker_bonus.c \
             $(SRC_DIR)/stack.c \
             $(SRC_DIR)/stack_utils.c \
             $(SRC_DIR)/ops_swap.c \
             $(SRC_DIR)/ops_push.c \
             $(SRC_DIR)/ops_rotate.c \
             $(SRC_DIR)/ops_reverse_rotate.c \
             $(SRC_DIR)/parsing.c \
             $(SRC_DIR)/parsing_args.c \
             $(SRC_DIR)/utils.c \
             $(SRC_DIR)/utils2.c \
             $(SRC_DIR)/disorder.c \
             $(SRC_DIR)/data.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS := $(OBJS_BONUS:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c $(INC_DIR)/push_swap.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

bonus: $(CHECKER)

$(CHECKER): $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft -o $(CHECKER)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus
