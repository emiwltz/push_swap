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

static int	add_number_to_stack(char *number, t_stack **stack)
{
	t_node	*node;

	if (!is_valid_digit(number))
		return (0);
	node = lst_newnode(number);
	if (!node)
		return (0);
	if (*stack)
	{
		lst_addnodeback(node, stack);
		return (1);
	}
	*stack = initialize_stack(node);
	if (!(*stack))
	{
		free(node);
		return (0);
	}
	return (1);
}

static int	fill_stack_from_split(char **numbers, t_stack **stack)
{
	size_t	i;

	i = 0;
	while (numbers[i])
	{
		if (!add_number_to_stack(numbers[i], stack))
			return (0);
		i++;
	}
	return (1);
}

int	populate_stack(char *value, t_stack **stack)
{
	char	**numbers;

	numbers = ft_split((const char *)value, ' ');
	if (!numbers)
		return (0);
	if (!fill_stack_from_split(numbers, stack) || !check_double(stack))
		return (clear_split(numbers));
	clear_split(numbers);
	return (1);
}
