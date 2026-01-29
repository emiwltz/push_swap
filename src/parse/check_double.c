/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:11:11 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/29 11:32:38 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(int *table,  size_t payload_count)
{
  size_t i;
  size_t j;

  i = 0;
  while (i < payload_count)
  {
	j = 0;
	while(j < payload_count)
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

int	*third_check(char **payload)
{
  size_t	i;
  int	*table;
  size_t	payload_count;

  i = 0;
  payload_count = count_payload(payload);
  table = malloc(sizeof(int) * payload_count);
  while(i < payload_count)
  {
	table[i] = ft_atoi(payload[i]);
	i++;
  }
  if(check_double(table, payload_count) == 1)
	return (NULL);
  return (table);
}


