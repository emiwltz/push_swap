/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:20:30 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/09 23:28:53 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx)
{
	rotate(stack_a);
	rotate(stack_b);
	ctx->rr_count++;
	ft_printf("rr\n");
}
