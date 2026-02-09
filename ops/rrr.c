/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:24:35 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/09 13:26:07 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
  reverse_rotate(stack_a);
  reverse_rotate(stack_b);
  ft_printf("rrr");
}
