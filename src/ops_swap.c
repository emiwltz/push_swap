/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = tmp;
}

void	op_sa(t_data *data, int print)
{
	swap_top(data->a);
	data->ops.sa++;
	data->ops.total++;
	if (print)
		ft_putendl_fd("sa", 1);
}

void	op_sb(t_data *data, int print)
{
	swap_top(data->b);
	data->ops.sb++;
	data->ops.total++;
	if (print)
		ft_putendl_fd("sb", 1);
}

void	op_ss(t_data *data, int print)
{
	swap_top(data->a);
	swap_top(data->b);
	data->ops.ss++;
	data->ops.total++;
	if (print)
		ft_putendl_fd("ss", 1);
}
