/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 21:49:23 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/16 14:09:17 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "push_swap.h"
#include <stddef.h>
#include <stdio.h>

const char* disorder_percentage(t_ctx ctx)
{
  size_t  disorder;
  disorder = ctx.disorder;
  const char  *disorder_percentage;

  disorder_percentage = ft_strjoin(ft_itoa(disorder / 100), ".");
  disorder_percentage = ft_strjoin(disorder_percentage, ft_itoa(disorder % 100));
  return (disorder_percentage);
}

size_t	compute_disorder(t_stack *a)
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
	return (mistakes * 10000 / total_pairs);
}
