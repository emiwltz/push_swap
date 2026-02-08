/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 10:33:10 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/08 13:19:03 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
  t_node *tmp;

  tmp = NULL;
  if (!stack || stack->size < 2)
	return ;
  tmp = stack->head;
  stack->head = stack->head->next;
  stack->head->next = tmp;
  stack->head->next = stack->head->next->next;
}

