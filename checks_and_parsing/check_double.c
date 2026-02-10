/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:11:11 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/10 14:37:22 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "push_swap.h"

// should num be long?
// int	check_double(char *number, t_stack **stack_a)
// {
// 	t_node	*node;
// 	int		num;
//
// 	if (!(*stack_a))
// 		return (1);
// 	num = ft_atoi(number);
// 	node = (*stack_a)->head;
// 	while (node != (*stack_a)->tail)
// 	{
// 		if (num == node->value)
// 			return (0);
// 		node = node->next;
// 	}
// 	if (num == node->value)
// 		return (0);
// 	return (1);
// }

int	check_double(t_stack **stack_a)
{
	t_node	*node;
	t_node	*cmp;

	if (!stack_a || !(*stack_a) || (*stack_a)->size < 2)
		return (1);
	node = (*stack_a)->head;
	while (node != (*stack_a)->tail)
	{
		cmp = node->next;
		while (cmp != (*stack_a)->head)
		{
			if (cmp->value == node->value)
				return (0);
			cmp = cmp->next;
		}
		node = node->next;
	}
	return (1);
}
