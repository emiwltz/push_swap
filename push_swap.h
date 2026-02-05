/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:23:29 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/05 15:15:32 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"

# define ERR_MSG "Error\n"
# define FLAG_BENCH "--bench"
# define FLAG_SIMPLE "--simple"
# define FLAG_MEDIUM "--medium"
# define FLAG_COMPLEX "--complex"
# define FLAG_ADAPTIVE "--adaptive"

# include <limits.h>

typedef enum e_algo
{
	ALGO_UNSET,
	ALGO_SIMPLE,
	ALGO_MEDIUM,
	ALGO_COMPLEX,
	ALGO_ADAPTIVE,
}					t_algo;

typedef struct s_ctx
{
	int				bench_enabled;
	t_algo			algo;
	int				flag_count;
	int				bench_count;
}					t_ctx;

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	size_t			size;
}					t_stack;

void				error_msg(void);
int					ft_strcmp(const char *str1, const char *str2);
int					is_digit_string(char *s);
int					first_check(char **argv, int argc, t_ctx ctx);
int					set_flags(char *str, t_ctx *ctx);
int					arg_is_valid(char *s);
void				print_error(void);
int					is_valid_digit(char *s);
char				**clean_flags(char **argv, int argc);
int					count_payload(char **payload);
int					*third_check(char **payload);
long				ft_atol(const char *str);
int					only_spaces(char *s);
int					compute_disorder(t_node node, t_stack start);
int					set_algo(char *flag, t_ctx *ctx);
int					check_double(int *table, size_t payload_count);
t_stack				*lst_newstack(t_node *node);
t_node				*lst_newnode(char *value);
void				lst_addnodeback(t_node *new, t_stack *stack);
void				lst_addnodefront(t_node **lst, t_node *new, t_stack *stack);
t_stack				*initialize_stack_a(t_node *node);
#endif
