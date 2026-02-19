/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:06:41 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/19 13:16:46 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_b, t_stack **stack_a, t_ctx *ctx)
{
	push(stack_b, stack_a);
	ctx->pa_count++;
	ft_printf("pa\n");
}
