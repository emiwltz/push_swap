/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:13:09 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/08 13:25:11 by ewaltz           ###   ########.fr       */
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
	t_node	*node;

	stack_a = NULL;
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
	node = stack_a->head;
	ft_printf("\n===\nnum first next:%p\n===\n", node);
	while (node != stack_a->tail)
	{
		ft_printf("\n===\nnum:%d\n===\n", node->value);
		node = node->next;
	}
	ft_printf("\n===\nnum:%d\n===\n", node->value);
	ft_printf("\n===\nnum next:%p\n===\n", node->next);
	ft_printf("\n$$$$$\nsize:%d\n$$$$$\n", stack_a->size);
	printf("\n@@@@@@\ndisorder: %.2f%%\n@@@@@@\n", compute_disorder(stack_a));
	lst_clear(&stack_a);
	// swap(stack_a);
	// while (node != stack_a->tail)
	// {
	// 	ft_printf("\n===\nnum:%d\n===\n", node->value);
	// 	node = node->next;
	// }
	free(ctx);
	return (0);
}
