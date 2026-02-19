/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 21:49:23 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/19 13:17:54 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "push_swap.h"
#include <stddef.h>
#include <stdio.h>

const char	*disorder_percentage(t_ctx ctx)
{
	size_t		disorder;
	const char	*disorder_percentage;

	disorder = ctx.disorder;
	disorder_percentage = ft_strjoin(ft_itoa(disorder / 100), ".");
	disorder_percentage = ft_strjoin(disorder_percentage, ft_itoa(disorder
				% 100));
	return (disorder_percentage);
}

size_t	compute_disorder(t_stack *a)
{
	size_t	disorder;
	size_t	mistakes;
	size_t	total_pairs;
	t_node	*i;
	t_node	*j;

	if (!a || !a->head || a->size < 2)
		return (0);
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
	disorder = mistakes * 10000 / total_pairs;
	if (mistakes > 0 && disorder == 0)
		disorder = 1;
	return (disorder);
}
