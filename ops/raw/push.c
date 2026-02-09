/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:05:06 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/09 11:40:18 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	push(t_stack **stack_a, t_stack **stack_b)
{
  if (!(*stack_b))
  {
	if (!(*stack_b = initialize_stack((*stack_a)->head)))
	{
	  lst_clear(stack_a);
	  lst_clear(stack_b);
	  return (0);
	}
	else {
	  (*stack_a)->tail->next = (*stack_a)->head->next;
	  (*stack_a)->head->next = NULL;
	  (*stack_a)-> head = (*stack_a)->tail->next;
	  (*stack_a)->size--;

	  // (*stack_b)->head->next = NULL;
	  // (*stack_a)->tail->next = (*stack_a)->head->next;
	  // (*stack_a)->head = (*stack_a)->head->next;
	  // (*stack_a)->size--;
	}
  }
  else 
  {
	(*stack_a)->tail->next = (*stack_a)->head->next;
	(*stack_b)->tail->next = (*stack_a)->head;
	(*stack_a)->head->next = (*stack_b)->head;
	(*stack_a)->head = (*stack_a)->tail->next;
	(*stack_b)->head = (*stack_b)->tail->next;
	(*stack_a)->size--;
	(*stack_b)->size++;
  }
  return (1);
}
