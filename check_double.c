/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:11:11 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/04 17:02:39 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(int *table, size_t payload_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < payload_count)
	{
		j = 0;
		while (j < payload_count)
		{
			if (i != j)
			{
				if (table[i] == table[j])
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
