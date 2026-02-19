/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_addnodefront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:59:17 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/19 13:03:06 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_addnodefront(t_node *new, t_stack **stack)
{
	if (!new || !(*stack))
		return ;
	new->next = (*stack)->head;
	(*stack)->head = new;
	(*stack)->tail->next = new;
	(*stack)->size++;
}
