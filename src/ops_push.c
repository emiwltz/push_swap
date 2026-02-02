/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_data *data, int print)
{
	int	value;

	if (data->b->size == 0)
		return ;
	value = stack_pop(data->b);
	stack_push(data->a, value);
	data->ops.pa++;
	data->ops.total++;
	if (print)
		ft_putendl_fd("pa", 1);
}

void	op_pb(t_data *data, int print)
{
	int	value;

	if (data->a->size == 0)
		return ;
	value = stack_pop(data->a);
	stack_push(data->b, value);
	data->ops.pb++;
	data->ops.total++;
	if (print)
		ft_putendl_fd("pb", 1);
}
