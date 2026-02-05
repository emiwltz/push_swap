/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_addnodeback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:41:20 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/05 15:36:40 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_addnodeback(t_node *new, t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	if (!new || !stack)
		return ;
	if (!temp)
	{
		new->next = NULL;
		stack->head = new;
		stack->tail = new;
		stack->size = 1;
		return ;
	}
	while (temp != stack->tail)
		temp = temp->next;
	temp->next = new;
	stack->tail = new;
	new->next = stack->head;
	stack->size++;
}
