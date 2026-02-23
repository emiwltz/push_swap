/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:29:01 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/23 16:33:28 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_int_range(char *s)
{
	if (s[0] == '-')
	{
		if (ft_strlen(s) > 11)
			return (0);
		if (ft_strlen(s) == 11 && ft_strcmp(s, "-2147483648") > 0)
			return (0);
	}
	else
	{
		if (ft_strlen(s) > 10)
			return (0);
		if (ft_strlen(s) == 10 && ft_strcmp(s, "2147483647") > 0)
			return (0);
	}
	return (1);
}

int	is_digit_string(char *s)
{
	int	i;

	i = 0;
	if (!check_int_range(s))
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != '-' && s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_digit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' && !ft_isdigit(s[i + 1]))
		return (0);
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
