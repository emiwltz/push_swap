/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:23:29 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/10 17:32:05 by ewaltz           ###   ########.fr       */
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
	size_t			rank;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	size_t			size;
}					t_stack;

int					ft_strcmp(const char *str1, const char *str2);
int					is_digit_string(char *s);
int					first_check(char **argv, int argc, t_ctx ctx,
						t_stack **stack_a);
int					set_flags(char *str, t_ctx *ctx);
int					arg_is_valid(char *s);
int				print_error(void);
int					is_valid_digit(char *s);
char				**clean_flags(char **argv, int argc);
long				ft_atol(const char *str);
int					only_spaces(char *s);
float				compute_disorder(t_stack *a);
int					set_algo(char *flag, t_ctx *ctx);
int					check_double(t_stack **stack_a);
t_stack				*lst_newstack(t_node *node);
t_node				*lst_newnode(char *value);
void				lst_addnodeback(t_node *new, t_stack **stack);
void				lst_addnodefront(t_node *new, t_stack **stack);
void				lst_clear(t_stack **lst);
t_stack				*initialize_stack(t_node *node);
void				swap(t_stack **stack);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);
int					push(t_stack **stack_a, t_stack **stack_b);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_b, t_stack **stack_a);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_b, t_stack **stack_a);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				set_ranks(t_stack **stack);
void				selection(t_stack **stack_a, t_stack **stack_b);
void				radix(t_stack **a, t_stack **b);
int         check_rank(t_stack **a);
void        chunk_based(t_stack **a, t_stack **b);
#endif
