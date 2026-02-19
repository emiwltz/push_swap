/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:15:26 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/19 13:16:50 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "push_swap.h"

void	ra(t_stack **stack_a, t_ctx *ctx)
{
	rotate(stack_a);
	ctx->ra_count++;
	ft_printf("ra\n");
}
