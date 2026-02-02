/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(double disorder)
{
	int	integer_part;
	int	decimal_part;

	integer_part = (int)(disorder * 100);
	decimal_part = (int)(disorder * 10000) % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(integer_part, 2);
	ft_putchar_fd('.', 2);
	if (decimal_part < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(decimal_part, 2);
	ft_putendl_fd("%", 2);
}

static void	print_strategy_name(t_strategy strategy)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (strategy == STRATEGY_SIMPLE)
		ft_putendl_fd("Simple / O(n^2)", 2);
	else if (strategy == STRATEGY_MEDIUM)
		ft_putendl_fd("Medium / O(n*sqrt(n))", 2);
	else if (strategy == STRATEGY_COMPLEX)
		ft_putendl_fd("Complex / O(n*log(n))", 2);
	else
		ft_putendl_fd("Adaptive / O(n*sqrt(n))", 2);
}

static void	print_ops_detail(t_data *data)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(data->ops.sa, 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putnbr_fd(data->ops.sb, 2);
	ft_putstr_fd("  ss: ", 2);
	ft_putnbr_fd(data->ops.ss, 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putnbr_fd(data->ops.pa, 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_fd(data->ops.pb, 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(data->ops.ra, 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_fd(data->ops.rb, 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putnbr_fd(data->ops.rr, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_fd(data->ops.rra, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_fd(data->ops.rrb, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(data->ops.rrr, 2);
	ft_putendl_fd("", 2);
}

void	print_benchmark(t_data *data)
{
	print_disorder(data->disorder);
	print_strategy_name(data->strategy);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(data->ops.total, 2);
	ft_putendl_fd("", 2);
	print_ops_detail(data);
}
