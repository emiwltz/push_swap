/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_addnodefront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:59:17 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/08 16:48:46 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_addnodefront(t_node *new, t_stack **stack)
{
	if (!new || !(*stack))
		return ;
	// node
	new->next = (*stack)->head;
	// stack->head
	(*stack)->head = new;
	// node tail to new
	(*stack)->tail->next = new;
	(*stack)->size++;
}
