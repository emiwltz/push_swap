/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*data_init(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = NULL;
	data->b = NULL;
	data->strategy = STRATEGY_ADAPTIVE;
	data->bench_mode = 0;
	data->disorder = 0.0;
	data->ops.sa = 0;
	data->ops.sb = 0;
	data->ops.ss = 0;
	data->ops.pa = 0;
	data->ops.pb = 0;
	data->ops.ra = 0;
	data->ops.rb = 0;
	data->ops.rr = 0;
	data->ops.rra = 0;
	data->ops.rrb = 0;
	data->ops.rrr = 0;
	data->ops.total = 0;
	return (data);
}

void	data_free(t_data *data)
{
	if (!data)
		return ;
	if (data->a)
		stack_free(data->a);
	if (data->b)
		stack_free(data->b);
	free(data);
}
