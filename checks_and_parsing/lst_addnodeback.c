/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_addnodeback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:41:20 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/19 13:02:56 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_addnodeback(t_node *new, t_stack **stack)
{
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
	(*stack)->tail->next = new;
	(*stack)->tail = new;
	new->next = (*stack)->head;
	(*stack)->size++;
}
