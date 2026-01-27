/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:25:55 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/27 15:44:06 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

char	**clean_flags(char **argv, int argc)
{
  char	*payload;
  int	i;

  payload = "";
  i = 1;
  while (i < argc)
  {
	if (is_digit_string(argv[i]) == 1)
	{
	  payload = ft_strjoin(payload, argv[i]);
	  payload = ft_strjoin(payload, " ");
	}
	i++;
  }
  ft_printf("%s\n", payload);
  return (ft_split(payload, ' '));
}

int	second_check(char **argv, int argc)
{
  int	i;
  char **int_table;

  i = 0;
  int_table = clean_flags(argv, argc);
  while (int_table[i] != NULL)
  {
	if (is_valid_digit(int_table[i]) == 0)
	  return (1);
	i++;
  }
  return (0);
}

int	first_check(char **argv, int argc, t_ctx ctx)
{
  int	i;

  i = 1;
  while(i < argc)
  {
	set_flags(argv[i], &ctx);
	if (argv[i][0] == '\0')
	  return (1);
	if (arg_is_valid(argv[i]) == 1)
	  return (1);
	i++;
  }
  if (ctx.flag_count > 1 || ctx.bench_count > 1)
	return (1);
  if (second_check(argv, argc) == 1)
	return (1);
  return (0);
}
