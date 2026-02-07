/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:11:11 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/05 22:01:00 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "push_swap.h"

// should num be long?
int	check_double(char *number, t_stack **stack_a)
{
	t_node	*node;
	int		num;

	if (!(*stack_a))
		return (1);
	num = ft_atoi(number);
	node = (*stack_a)->head;
	while (node != (*stack_a)->tail)
	{
		if (num == node->value)
			return (0);
		node = node->next;
	}
	if (num == node->value)
		return (0);
	return (1);
}
