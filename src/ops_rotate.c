/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->data[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->size - 1] = tmp;
}

void	op_ra(t_data *data, int print)
{
	rotate(data->a);
	data->ops.ra++;
	data->ops.total++;
	if (print)
		ft_putendl_fd("ra", 1);
}

void	op_rb(t_data *data, int print)
{
	rotate(data->b);
	data->ops.rb++;
	data->ops.total++;
	if (print)
		ft_putendl_fd("rb", 1);
}

void	op_rr(t_data *data, int print)
{
	rotate(data->a);
	rotate(data->b);
	data->ops.rr++;
	data->ops.total++;
	if (print)
		ft_putendl_fd("rr", 1);
}
