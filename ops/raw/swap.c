/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 10:33:10 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/08 16:53:17 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
  if (!(*stack) || (*stack)->size < 2) 
	return ;

  (*stack)->tail->next = (*stack)->head->next;
  (*stack)->head->next = (*stack)->head->next->next;
  (*stack)->tail->next->next = (*stack)->head;
  (*stack)->head = (*stack)->tail->next;
}

