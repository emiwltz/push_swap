/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>

typedef enum e_strategy
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE
}	t_strategy;

typedef struct s_stack
{
	int				*data;
	int				size;
	int				capacity;
}	t_stack;

typedef struct s_ops_count
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}	t_ops_count;

typedef struct s_data
{
	t_stack			*a;
	t_stack			*b;
	t_strategy		strategy;
	int				bench_mode;
	double			disorder;
	t_ops_count		ops;
}	t_data;

/* Stack operations */
t_stack		*stack_init(int capacity);
void		stack_free(t_stack *stack);
void		stack_push(t_stack *stack, int value);
int			stack_pop(t_stack *stack);
int			stack_peek(t_stack *stack);
int			stack_peek_bottom(t_stack *stack);
int			stack_is_empty(t_stack *stack);
int			stack_is_sorted(t_stack *stack);
void		stack_copy(t_stack *dst, t_stack *src);

/* Push_swap operations */
void		op_sa(t_data *data, int print);
void		op_sb(t_data *data, int print);
void		op_ss(t_data *data, int print);
void		op_pa(t_data *data, int print);
void		op_pb(t_data *data, int print);
void		op_ra(t_data *data, int print);
void		op_rb(t_data *data, int print);
void		op_rr(t_data *data, int print);
void		op_rra(t_data *data, int print);
void		op_rrb(t_data *data, int print);
void		op_rrr(t_data *data, int print);

/* Parsing */
int			parse_args(int argc, char **argv, t_data *data);
int			is_valid_int(const char *str);
int			has_duplicates(t_stack *stack);
void		error_exit(t_data *data);
void		free_split(char **split);

/* Disorder metric */
double		compute_disorder(t_stack *stack);

/* Sorting algorithms */
void		sort_simple(t_data *data);
void		sort_medium(t_data *data);
void		sort_complex(t_data *data);
void		sort_adaptive(t_data *data);

/* Small sort utilities */
void		sort_two(t_data *data);
void		sort_three(t_data *data);
void		sort_four(t_data *data);
void		sort_five(t_data *data);
void		sort_small(t_data *data);

/* Utils */
int			get_min(t_stack *stack);
int			get_max(t_stack *stack);
int			get_min_pos(t_stack *stack);
int			get_max_pos(t_stack *stack);
int			get_pos_of_value(t_stack *stack, int value);
void		normalize_stack(t_stack *stack);
int			*get_sorted_array(t_stack *stack);
void		rotate_to_top(t_data *data, int pos, char stack_name);

/* Benchmark */
void		print_benchmark(t_data *data);

/* Data management */
t_data		*data_init(void);
void		data_free(t_data *data);

#endif
