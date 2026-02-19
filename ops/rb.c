/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:19:22 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/19 13:16:53 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "push_swap.h"

void	rb(t_stack **stack_b, t_ctx *ctx)
{
	rotate(stack_b);
	ctx->rb_count++;
	ft_printf("rb\n");
}
