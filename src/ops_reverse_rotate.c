/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->data[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = tmp;
}

void	op_rra(t_data *data, int print)
{
	reverse_rotate(data->a);
	data->ops.rra++;
	data->ops.total++;
	if (print)
		ft_putendl_fd("rra", 1);
}

void	op_rrb(t_data *data, int print)
{
	reverse_rotate(data->b);
	data->ops.rrb++;
	data->ops.total++;
	if (print)
		ft_putendl_fd("rrb", 1);
}

void	op_rrr(t_data *data, int print)
{
	reverse_rotate(data->a);
	reverse_rotate(data->b);
	data->ops.rrr++;
	data->ops.total++;
	if (print)
		ft_putendl_fd("rrr", 1);
}
