/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:13:09 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/21 13:37:48 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "push_swap.h"

void	ctx_init(t_ctx **ctx)
{
	(*ctx)->algo = ALGO_ADAPTIVE;
	(*ctx)->bench_enabled = 0;
	(*ctx)->flag_count = 0;
	(*ctx)->bench_count = 0;
	(*ctx)->pa_count = 0;
	(*ctx)->pb_count = 0;
	(*ctx)->ra_count = 0;
	(*ctx)->rb_count = 0;
	(*ctx)->rr_count = 0;
	(*ctx)->rra_count = 0;
	(*ctx)->rrb_count = 0;
	(*ctx)->rrr_count = 0;
	(*ctx)->sa_count = 0;
	(*ctx)->sb_count = 0;
	(*ctx)->ss_count = 0;
}

static int	exit_program(t_ctx *ctx, t_stack **stack_a, t_stack **stack_b,
		int print_err)
{
	if (*stack_a)
		lst_clear(stack_a);
	if (*stack_b)
		lst_clear(stack_b);
	free(ctx);
	if (print_err)
		return (print_error());
	return (0);
}

int	main(int argc, char **argv)
{
	t_ctx	*ctx;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
		return (print_error());
	ctx_init(&ctx);
	if (argc < 2)
		return (exit_program(ctx, &stack_a, &stack_b, 0));
	if (!iterate_args(argv, argc, &ctx, &stack_a))
		return (exit_program(ctx, &stack_a, &stack_b, 1));
	choose_algo(&stack_a, &stack_b, ctx);
	return (exit_program(ctx, &stack_a, &stack_b, 0));
}
