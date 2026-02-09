/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:05:06 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/09 22:45:43 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	push(t_stack **stack_from, t_stack **stack_to)
{
	if (!(*stack_to))
	{
		if (!(*stack_to = initialize_stack((*stack_from)->head)))
		{
			lst_clear(stack_from);
			lst_clear(stack_to);
			return (0);
		}
		else
		{
			(*stack_from)->tail->next = (*stack_from)->head->next;
			(*stack_from)->head->next = NULL;
			(*stack_from)->head = (*stack_from)->tail->next;
			(*stack_from)->size--;
		}
	}
	else
	{
		if ((*stack_from)->size == 1)
		{
			(*stack_to)->tail->next = (*stack_from)->head;
			(*stack_from)->head->next = (*stack_to)->head;
			(*stack_to)->head = (*stack_to)->tail->next;
			(*stack_from)->head = NULL;
			(*stack_from)->tail = NULL;
			(*stack_from)->size--;
			(*stack_to)->size++;
			lst_clear(stack_from);
		}
		else
		{
			(*stack_from)->tail->next = (*stack_from)->head->next;
			(*stack_to)->tail->next = (*stack_from)->head;
			(*stack_from)->head->next = (*stack_to)->head;
			(*stack_from)->head = (*stack_from)->tail->next;
			(*stack_to)->head = (*stack_to)->tail->next;
			(*stack_from)->size--;
			(*stack_to)->size++;
		}
	}
	return (1);
}
