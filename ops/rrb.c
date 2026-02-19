/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:23:51 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/19 13:17:01 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack **stack_b, t_ctx *ctx)
{
	reverse_rotate(stack_b);
	ctx->rrb_count++;
	ft_printf("rrb\n");
}
