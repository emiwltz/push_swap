/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_newnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:38:28 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/19 12:01:09 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_newnode(char *value)
{
	t_node *res;

	res = malloc(sizeof(t_node));
	if (!res)
		return (NULL);
	res->value = ft_atoi(value);
	res->rank = 1;
	res->next = NULL;
	return (res);
}
