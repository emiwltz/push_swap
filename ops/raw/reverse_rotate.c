/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:55:47 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/08 17:02:42 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
  t_node *temp;

  temp = (*stack)->head;
  while (temp->next != (*stack)->tail)
	temp = temp->next;
  (*stack)->tail = temp;
  (*stack)->head = (*stack)->tail->next;
}
