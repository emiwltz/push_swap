/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:13:09 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/09 19:01:35 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ctx_init(t_ctx *ctx)
{
	ctx->algo = ALGO_UNSET;
	ctx->bench_enabled = 0;
	ctx->flag_count = 0;
	ctx->bench_count = 0;
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_ctx	*ctx;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node	*node_a;
	t_node	*node_b;

	(void)node_a;
	(void)node_b;
	stack_a = NULL;
	stack_b = NULL;
	ctx = malloc(sizeof(t_ctx));
	ctx_init(ctx);
	if (argc < 2)
		return (1);
	if (first_check(argv, argc, *ctx, &stack_a))
	{
		free(ctx);
		if (stack_a)
			lst_clear(&stack_a);
		print_error();
		return (1);
	}
	node_a = stack_a->head;
	while (node_a != stack_a->tail)
	{
		printf("\n===\nnum:%d  (%d)\n===\n", node_a->value, node_a->rank);
		node_a = node_a->next;
	}
	printf("\n===\nnum:%d  (%d)\n===\n", node_a->value, node_a->rank);
	printf("\n$$$$$\nsize:%zu\n$$$$$\n", stack_a->size);
	printf("\n@@@@@@\ndisorder: %.2f%%\n@@@@@@\n", compute_disorder(stack_a));
	if (stack_a)
		lst_clear(&stack_a);
	if (stack_b)
		lst_clear(&stack_b);
	free(ctx);
	return (0);
}
