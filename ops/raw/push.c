/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:05:06 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/20 12:14:01 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	emptying_stack(t_stack **stack_from, t_stack **stack_to)
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

static void	update_stack_from(t_stack **stack_from)
{
	(*stack_from)->tail->next = (*stack_from)->head->next;
	(*stack_from)->head->next = NULL;
	(*stack_from)->head = (*stack_from)->tail->next;
	(*stack_from)->size--;
}

static void	regular_push(t_stack **stack_from, t_stack **stack_to)
{
	(*stack_from)->tail->next = (*stack_from)->head->next;
	(*stack_to)->tail->next = (*stack_from)->head;
	(*stack_from)->head->next = (*stack_to)->head;
	(*stack_from)->head = (*stack_from)->tail->next;
	(*stack_to)->head = (*stack_to)->tail->next;
	(*stack_from)->size--;
	(*stack_to)->size++;
}

static int	error_initializing(t_stack **stack_from, t_stack **stack_to)
{
	lst_clear(stack_from);
	lst_clear(stack_to);
	return (0);
}

int	push(t_stack **stack_from, t_stack **stack_to)
{
	if (!(*stack_to))
	{
		*stack_to = initialize_stack((*stack_from)->head);
		if (!(*stack_to))
			return (error_initializing(stack_from, stack_to));
		else
			update_stack_from(stack_from);
	}
	else
	{
		if ((*stack_from)->size == 1)
			emptying_stack(stack_from, stack_to);
		else
			regular_push(stack_from, stack_to);
	}
	return (1);
}
