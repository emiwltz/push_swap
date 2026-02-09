/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:13:09 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/09 11:41:55 by ewaltz           ###   ########.fr       */
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
	printf("\n===\nnum first next:%p\n===\n", node_a);
	printf("\n===\nnum second next:%p\n===\n", node_a->next);
	while (node_a != stack_a->tail)
	{
		printf("\n===\nnum:%d\n===\n", node_a->value);
		node_a = node_a->next;
	}
	printf("\n===\nnum:%d\n===\n", node_a->value);
	printf("\n===\nnum next:%p\n===\n", node_a->next);
	printf("\n$$$$$\nsize:%zu\n$$$$$\n", stack_a->size);
	printf("\n@@@@@@\ndisorder: %.2f%%\n@@@@@@\n", compute_disorder(stack_a));
	// swap(&stack_a);
	// node_a = stack_a->head;
	// printf("\nswap*********************************\n");
	// while (node_a != stack_a->tail)
	// {
	// 	printf("\n===\nnum:%d\n===\n", node_a->value);
	// 	node_a = node_a->next;
	// }
	// printf("\n===\nnum:%d\n===\n", node_a->value);
	// printf("\n===\nnum next:%p\n===\n", node_a->next);
	// rotate(&stack_a);
	// node_a = stack_a->head;
	// printf("\nrotate*********************************\n");
	// while (node_a != stack_a->tail)
	// {
	// 	printf("\n===\nnum:%d\n===\n", node_a->value);
	// 	node_a = node_a->next;
	// }
	// printf("\n===\nnum:%d\n===\n", node_a->value);
	// printf("\n===\nnum next:%p\n===\n", node_a->next);
	// reverse_rotate(&stack_a);
	// node_a = stack_a->head;
	// printf("\nreverse_rotate*********************************\n");
	// while (node_a != stack_a->tail)
	// {
	// 	printf("\n===\nnum:%d\n===\n", node_a->value);
	// 	node_a = node_a->next;
	// }
	// printf("\n===\nnum:%d\n===\n", node_a->value);
	// printf("\n===\nnum next:%p\n===\n", node_a->next);
	// printf("\n&&&\nhead: %d\ntail: %d\n&&&\n", stack_a->head->value, stack_a->tail->value);



	push(&stack_a, &stack_b);
	node_a = stack_a->head;
	node_b = stack_b->head;
	printf("\npush*********************************\n");
	printf("\n&&&\na->head: %d\na->stack_tail: %d\n&&&\n", stack_a->head->value, stack_a->tail->value);
	printf("\n&&&\nhead: %d\ntail: %d\n&&&\n", stack_b->head->value, stack_b->tail->value);
	while (node_a != stack_a->tail)
	{
		printf("\n===\nnum:%d\n===\n", node_a->value);
		node_a = node_a->next;
	}
	printf("\n===\nnum:%d\n===\n", node_a->value);
	printf("\n===\nnum next:%p\n===\n", node_a->next);
	while (node_b != stack_b->tail)
	{
		printf("\n===\nnum:%d\n===\n", node_b->value);
		node_b = node_b->next;
	}
	printf("\n===\nnum:%d\n===\n", node_b->value);
	printf("\n===\nnum next:%p\n===\n", node_b->next);



	lst_clear(&stack_a);
	free(ctx);
	return (0);
}
