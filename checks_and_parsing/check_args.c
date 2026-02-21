/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:25:55 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/20 11:08:04 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

char	**arg_is_valid_helper(char *s)
{
	char	**numbers;

	if (only_spaces(s))
		return (0);
	numbers = ft_split((const char *)s, ' ');
	if (!numbers)
		return (0);
	return (numbers);
}

int	arg_is_valid(char *s)
{
	size_t	i;
	char	**numbers;

	numbers = arg_is_valid_helper(s);
	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i])
	{
		if (!is_digit_string(numbers[i])
			|| (ft_atol(numbers[i]) > INT_MAX || ft_atol(numbers[i]) < INT_MIN))
		{
			i = -1;
			while (numbers[++i])
				free(numbers[i]);
			free(numbers);
			return (0);
		}
		i++;
	}
	i = -1;
	while (numbers[++i])
		free(numbers[i]);
	free(numbers);
	return (1);
}
