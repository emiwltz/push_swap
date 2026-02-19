/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:09:05 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/19 13:21:34 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	clear_split(char **numbers)
{
	size_t	i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (0);
}

t_stack	*initialize_stack(t_node *node)
{
	t_stack	*res;

	if (!node)
		return (NULL);
	res = lst_newstack(node);
	if (!res)
		return (NULL);
	return (res);
}

int	populate_stack(char *value, t_stack **stack)
{
	size_t	i;
	char	**numbers;
	t_node	*node;

	numbers = ft_split((const char *)value, ' ');
	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i])
	{
		if (is_valid_digit(numbers[i]))
		{
			if (!(node = lst_newnode(numbers[i])))
				return (clear_split(numbers));
			if (*stack)
				lst_addnodeback(node, stack);
			else if (!(*stack = initialize_stack(node)))
				return (clear_split(numbers));
		}
		else
			return (clear_split(numbers));
		i++;
	}
	if (!check_double(stack))
		return (clear_split(numbers));
	clear_split(numbers);
	return (1);
}
