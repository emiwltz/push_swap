NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -MMD -MP -g3

SRCS        = \
              main.c\
			  ft_strcmp.c\
			  check_args.c\
			  set_flags.c\
			  check_string.c\
			  print_error.c\
			  count_payload.c \
			  check_double.c \
			  ft_atol.c \
			  only_spaces.c \
			  lst_addnodeback.c \
			  lst_addnodefront.c \
			  lst_newnode.c \
			  lst_newstack.c \

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
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT)/ clean
	rm -f $(OBJS) $(DEPS)
	rm -fd $(BUILD_DIR)

fclean: clean
	make -C $(LIBFT)/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)