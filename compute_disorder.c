/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 21:49:23 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/05 22:39:34 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

float	compute_disorder(t_stack *a)
{
	size_t	mistakes;
	size_t	total_pairs;
	t_node	*i;
	t_node	*j;

	i = a->head;
	mistakes = 0;
	total_pairs = 0;
	while (i != a->tail)
	{
		j = i->next;
		while (j != a->tail)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		total_pairs++;
		if (i->value > j->value)
			mistakes++;
		i = i->next;
	}
	ft_printf("\n--->\nmistakes: %d\n<---\n", mistakes);
	ft_printf("\n--->\npairs: %d\n<---\n", total_pairs);
	return ((float)mistakes / (float)total_pairs * 100);
}
