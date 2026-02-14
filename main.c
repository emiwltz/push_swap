/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:13:09 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/10 18:40:17 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "push_swap.h"

void	ctx_init(t_ctx *ctx)
{
	ctx->algo = ALGO_UNSET;
	ctx->bench_enabled = 0;
	ctx->flag_count = 0;
	ctx->bench_count = 0;
	ctx->pa_count = 0;
	ctx->pb_count = 0;
	ctx->ra_count = 0;
	ctx->rb_count = 0;
	ctx->rr_count = 0;
	ctx->rra_count = 0;
	ctx->rrb_count = 0;
	ctx->rrr_count = 0;
	ctx->sa_count = 0;
	ctx->sb_count = 0;
	ctx->ss_count = 0;

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
	if (!ctx)
		return (0);
	ctx_init(ctx);
	if (argc < 2)
	{
		free(ctx);
		return (0);
	}
	if (first_check(argv, argc, *ctx, &stack_a))
	{
		free(ctx);
		if (stack_a)
			lst_clear(&stack_a);
		return(print_error());
	}
	choose_algo(&stack_a, &stack_b, ctx);











	node_a = stack_a->head;
	while (node_a != stack_a->tail)
	{
		printf("\n===\nnum:%d  (%zu)\n===\n", node_a->value, node_a->rank);
		node_a = node_a->next;
	}
	printf("\n===\nnum:%d  (%zu)\n===\n", node_a->value, node_a->rank);
	printf("\n$$$$$\nsize:%zu\n$$$$$\n", stack_a->size);
	printf("\n@@@@@@\ndisorder: %.2f%%\n@@@@@@\n", compute_disorder(stack_a));
	if (stack_b)
	{
		node_b = stack_b->head;
		while (node_b != stack_b->tail)
		{
			printf("\n===\nnum:%d  (%zu)\n===\n", node_b->value, node_b->rank);
			node_b = node_b->next;
		}
		printf("\n===\nnum:%d  (%zu)\n===\n", node_b->value, node_b->rank);
		printf("\n$$$$$\nsize:%zu\n$$$$$\n", stack_b->size);
	}
  
	ft_printf("----------------apres--------------------");
	radix(&stack_a, &stack_b, ctx);
	node_a = stack_a->head;
	while (node_a != stack_a->tail)
	{
		printf("\n===\nnum:%d  (%zu)\n===\n", node_a->value, node_a->rank);
		node_a = node_a->next;
	}
	printf("\n===\nnum:%d  (%zu)\n===\n", node_a->value, node_a->rank);

	// sa(&stack_a, ctx);
	// sb(&stack_b, ctx);
	// ss(&stack_b, &stack_a, ctx);
	// ra(&stack_a, ctx);
	// rb(&stack_b, ctx);
	// rr(&stack_a, &stack_b, ctx);
	// rra(&stack_a, ctx);
	// rrb(&stack_b, ctx);
	// rrr(&stack_a, &stack_b, ctx);
	// pa(&stack_b, &stack_a, ctx);
	// pb(&stack_a, &stack_b, ctx);
	// ft_printf("----------------apres--------------------");
	// node_a = stack_a->head;
	// while (node_a != stack_a->tail)
	// {
	// 	printf("\n===\nnum:%d  (%zu)\n===\n", node_a->value, node_a->rank);
	// 	node_a = node_a->next;
	// }
	// printf("\n===\nnum:%d  (%zu)\n===\n", node_a->value, node_a->rank);
	// printf("\n$$$$$\nsize:%zu\n$$$$$\n", stack_a->size);
	// printf("\n@@@@@@\ndisorder: %.2f%%\n@@@@@@\n", compute_disorder(stack_a));
	// if (stack_b)
	// {
	// 	node_b = stack_b->head;
	// 	while (node_b != stack_b->tail)
	// 	{
	// 		printf("\n===\nnum:%d  (%zu)\n===\n", node_b->value, node_b->rank);
	// 		node_b = node_b->next;
	// 	}
	// 	printf("\n===\nnum:%d  (%zu)\n===\n", node_b->value, node_b->rank);
	// 	printf("\n$$$$$\nsize:%zu\n$$$$$\n", stack_b->size);
	// }
	// // printf("\n88888888888888888888888888\nselection\n88888888888888888888888888\n");
	// // selection(&stack_a, &stack_b, ctx);
	// // node_a = stack_a->head;
	// // while (node_a != stack_a->tail)
	// // {
	// // 	printf("\n===\nnum:%d  (%zu)\n===\n", node_a->value, node_a->rank);
	// // 	node_a = node_a->next;
	// // }
	// // printf("\n===\nnum:%d  (%zu)\n===\n", node_a->value, node_a->rank);
	// // printf("\n$$$$$\nsize:%zu\n$$$$$\n", stack_a->size);
	// // if (stack_b)
	// // {
	// // 	node_b = stack_b->head;
	// // 	while (node_b != stack_b->tail)
	// // 	{
	// // 		printf("\n===\nnum:%d  (%zu)\n===\n", node_b->value, node_b->rank);
	// // 		node_b = node_b->next;
	// // 	}
	// // 	printf("\n===\nnum:%d  (%zu)\n===\n", node_b->value, node_b->rank);
	// // 	printf("\n$$$$$\nsize:%zu\n$$$$$\n", stack_b->size);
	// // 	printf("\n222222222222222\n%p\n222222222222222\n", stack_b->head);
	// // }
	// if (stack_b)
	// 	test = 1;
	// else
	// 	test = 0;
	// printf("\n!!!!!!!!!!!!\n%d\n!!!!!!!!!!!!\n", test);
	if (stack_a)
		lst_clear(&stack_a);
	if (stack_b)
		lst_clear(&stack_b);
	free(ctx);
	return (0);
}
