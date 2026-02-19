/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:55:47 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/19 13:16:35 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_node	*temp;

	temp = (*stack)->head;
	while (temp->next != (*stack)->tail)
		temp = temp->next;
	(*stack)->tail = temp;
	(*stack)->head = (*stack)->tail->next;
}
