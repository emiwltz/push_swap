/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_newstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:51:17 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/05 13:54:18 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_newstack(t_node *node)
{
	t_stack *res;

	res = malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->head = node;
	res->tail = node;
	res->size = 0;
	return (res);
}