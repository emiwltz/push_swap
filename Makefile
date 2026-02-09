NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -MMD -MP -g3 -I.

SRCS        = \
              main.c\
			  utils/ft_strcmp.c\
			  checks_and_parsing/check_args.c\
			  checks_and_parsing/set_flags.c\
			  utils/check_string.c\
			  utils/print_error.c\
			  checks_and_parsing/check_double.c \
			  utils/ft_atol.c \
			  utils/only_spaces.c \
			  checks_and_parsing/lst_addnodeback.c \
			  checks_and_parsing/lst_addnodefront.c \
			  checks_and_parsing/lst_newnode.c \
			  checks_and_parsing/lst_newstack.c \
			  checks_and_parsing/lst_clear.c \
			  checks_and_parsing/set_ranks.c \
			  utils/compute_disorder.c \
			  ops/swap.c \
			  ops/rotate.c \
			  ops/reverse_rotate.c \
			  ops/push.c \

OBJS        = $(addprefix $(BUILD_DIR), $(SRCS:.c=.o))
DEPS		= $(OBJS:.o=.d)

BUILD_DIR 	= .build/

LIBFT		= libft
LIBFT_DIR   = libft/
LIBFT_NAME  = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(NAME)

$(BUILD_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT)/ clean
	rm -f $(OBJS) $(DEPS)
	rm -rf $(BUILD_DIR)

fclean: clean
	make -C $(LIBFT)/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
