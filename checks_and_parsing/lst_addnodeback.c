/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_addnodeback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:41:20 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/08 13:46:04 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_addnodeback(t_node *new, t_stack **stack)
{
	// t_node	*temp;

	// temp = (*stack)->tail;
	if (!new || !stack)
		return ;
	if (!(*stack)->tail)
	{
		new->next = NULL;
		(*stack)->head = new;
		(*stack)->tail = new;
		(*stack)->size = 1;
		return ;
	}
	// change node to point to new last
	(*stack)->tail->next = new;
	// change stack->tail to new last node address
	(*stack)->tail = new;
	// point new last node to head node
	new->next = (*stack)->head;
	// adjust size of stack
	(*stack)->size++;
}
