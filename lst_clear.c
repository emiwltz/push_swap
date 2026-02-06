/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:15:49 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/06 14:46:09 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_clear(t_stack **stack)
{
	t_node *temp;
	t_node *n;

	if (!stack)
		return ;
	temp = (*stack)->head;
	while (temp != (*stack)->tail)
	{
		n = temp->next;
		free(temp);
		temp = n;
	}
	free(temp);
	free(*stack);
}