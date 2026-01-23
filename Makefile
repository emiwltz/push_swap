NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
INCLUDES    = -Iincludes -Ilibft/includes

SRCS        = \
              src/main.c\
			  src/utils/ft_strcmp.c\
			  src/parse/parsing.c\
			  src/parse/set_and_check.c\
			  src/utils/check_string.c\

OBJS        = $(SRCS:.c=.o)

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c includes/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
