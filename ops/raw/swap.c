/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 10:33:10 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/19 13:16:41 by alemyre          ###   ########.fr       */
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
