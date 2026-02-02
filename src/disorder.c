/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *stack)
{
	int		mistakes;
	int		total_pairs;
	int		i;
	int		j;

	if (stack->size <= 1)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			total_pairs++;
			if (stack->data[i] > stack->data[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}
