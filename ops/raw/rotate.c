/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:46:25 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/08 16:51:14 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack **stack)
{
  t_node *temp;

  temp = (*stack)->head;
  (*stack)->head = temp->next;
  (*stack)->tail = temp;
}

