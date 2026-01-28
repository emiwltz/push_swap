/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:11:11 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/28 16:11:31 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_double(int **table)
{

}

int	*third_check(char **argv, int argc)
{
  int	i;
  int	*table;

  i = 0;
  table = malloc(sizeof(int) * argc);
  while(i < argc)
  {
	table[i] = ft_atoi(argv[i]);
	i++;
  }
  check_double(table);
  return (NULL);
}


