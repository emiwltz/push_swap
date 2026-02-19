/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:10:22 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/19 13:16:48 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx)
{
	push(stack_a, stack_b);
	ctx->pb_count++;
	ft_printf("pb\n");
}
