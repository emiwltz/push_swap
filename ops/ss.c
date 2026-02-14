/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:27:14 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/09 23:29:16 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **stack_b, t_stack **stack_a, t_ctx *ctx)
{
	swap(stack_b);
	swap(stack_a);
	ctx->ss_count++;
	ft_printf("ss\n");
}
