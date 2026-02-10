/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:25:55 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/10 13:31:49 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "push_swap.h"
#include <limits.h>

// char	**clean_flags(char **argv, int argc)
// {
// 	char	*payload;
// 	int		i;

// 	payload = "";
// 	i = 1;
// 	while (i < argc)
// 	{
// 		if (is_digit_string(argv[i]))
// 		{
// 			if (payload[0])
// 				payload = ft_strjoin(payload, " ");
// 			payload = ft_strjoin(payload, argv[i]);
// 		}
// 		i++;
// 	}
// 	ft_printf("%s\n", payload);
// 	return (ft_split(payload, ' '));
// }

int	arg_is_valid(char *s)
{
	size_t	i;
	char	**numbers;

	if(only_spaces(s))
	  return (0);
	numbers = ft_split((const char *)s, ' ');
	if(!numbers)
	  return (0);
	i = 0;
	while (numbers[i])
	{
		if (!is_digit_string(numbers[i]) || only_spaces(s)
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
