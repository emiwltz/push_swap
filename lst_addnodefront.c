/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_addnodefront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:59:17 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/05 14:02:14 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_addnodefront(t_node **lst, t_node *new, t_stack *stack)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
	stack->head = new;
	stack->size++;
}