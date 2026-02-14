/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:24:35 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/09 23:29:05 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ctx->rrr_count++;
	ft_printf("rrr\n");
}
