NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -MMD -MP -g3
AR			= ar rcs

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

OBJS        = $(addprefix $(BUILD_DIR), $(SRCS:.c=.o))
DEPS		= $(OBJS:.o=.d)

BUILD_DIR 	= .build/

LIBFT		= libft
LIBFT_DIR   = libft/
LIBFT_NAME  = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp $(addprefix $(LIBFT_DIR), $(LIBFT_NAME)) .
	mv $(LIBFT_NAME) $(NAME)
	$(AR) $(NAME) $(OBJS)


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