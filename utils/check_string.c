/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:29:01 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/19 13:17:47 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "push_swap.h"

int	is_digit_string(char *s)
{
	int	i;

	i = 0;
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
