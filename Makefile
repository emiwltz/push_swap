NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -MMD -MP -g3 -I.

SRCS        = \
              main.c\
			  utils/ft_strcmp.c\
			  utils/check_string.c\
			  utils/print_error.c\
			  utils/ft_atol.c \
			  utils/only_spaces.c \
			  utils/compute_disorder.c \
			  utils/check_order.c \
			  utils/choose_algo.c \
			  utils/bench.c \
			  checks_and_parsing/check_args.c\
			  checks_and_parsing/iterate_args.c\
			  checks_and_parsing/check_double.c \
			  checks_and_parsing/lst_addnodeback.c \
			  checks_and_parsing/lst_addnodefront.c \
			  checks_and_parsing/lst_newnode.c \
			  checks_and_parsing/lst_newstack.c \
			  checks_and_parsing/lst_clear.c \
			  checks_and_parsing/set_ranks.c \
			  checks_and_parsing/populate_stack.c \
			  ops/raw/swap.c \
			  ops/raw/rotate.c \
			  ops/raw/reverse_rotate.c \
			  ops/raw/push.c \
			  ops/pa.c \
			  ops/pb.c \
			  ops/sa.c \
			  ops/sb.c \
			  ops/ss.c \
			  ops/ra.c \
			  ops/rb.c \
			  ops/rr.c \
			  ops/rra.c \
			  ops/rrb.c \
			  ops/rrr.c \
			  sorts/selection.c \
			  sorts/radix.c \
			  sorts/chunk_based.c \

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
