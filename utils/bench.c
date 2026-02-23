/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:02:50 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/23 16:32:46 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*disp_algo(t_ctx **ctx)
{
	if ((*ctx)->algo == ALGO_SIMPLE)
		return ("Simple (O(n^2))");
	else if ((*ctx)->algo == ALGO_MEDIUM)
		return ("Medium (O(n*sqrt(n)))");
	else if ((*ctx)->algo == ALGO_COMPLEX)
		return ("Complex (O(n log n))");
	else if ((*ctx)->algo == ALGO_ADAPTIVE)
		return ("Adaptive");
	return ("Unset");
}

int	total_ops(t_ctx **ctx)
{
	int	total_ops;

	total_ops = (*ctx)->pa_count + (*ctx)->pb_count;
	total_ops += (*ctx)->ra_count + (*ctx)->rb_count + (*ctx)->rr_count;
	total_ops += (*ctx)->rra_count + (*ctx)->rrb_count + (*ctx)->rrr_count;
	total_ops += (*ctx)->sa_count + (*ctx)->sb_count + (*ctx)->ss_count;
	return (total_ops);
}

void	print_disorder(t_ctx **ctx)
{
	int	disorder;

	disorder = (*ctx)->disorder;
	ft_putstr_fd("| Disorder     : ", 2);
	ft_putnbr_fd(disorder / 100, 2);
	ft_putstr_fd(".", 2);
	if (disorder % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(disorder % 100, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_ops_table(t_ctx **ctx)
{
	ft_putstr_fd("		| OPS |\n", 2);
	ft_putstr_fd("| push       : pa=", 2);
	ft_putnbr_fd((*ctx)->pa_count, 2);
	ft_putstr_fd("  pb=", 2);
	ft_putnbr_fd((*ctx)->pb_count, 2);
	ft_putstr_fd("\n| rotate     : ra=", 2);
	ft_putnbr_fd((*ctx)->ra_count, 2);
	ft_putstr_fd("  rb=", 2);
	ft_putnbr_fd((*ctx)->rb_count, 2);
	ft_putstr_fd("  rr=", 2);
	ft_putnbr_fd((*ctx)->rr_count, 2);
	ft_putstr_fd("\n| rev_rotate : rra=", 2);
	ft_putnbr_fd((*ctx)->rra_count, 2);
	ft_putstr_fd(" rrb=", 2);
	ft_putnbr_fd((*ctx)->rrb_count, 2);
	ft_putstr_fd(" rrr=", 2);
	ft_putnbr_fd((*ctx)->rrr_count, 2);
	ft_putstr_fd("\n| swap       : sa=", 2);
	ft_putnbr_fd((*ctx)->sa_count, 2);
	ft_putstr_fd("  sb=", 2);
	ft_putnbr_fd((*ctx)->sb_count, 2);
	ft_putstr_fd("  ss=", 2);
	ft_putnbr_fd((*ctx)->ss_count, 2);
	ft_putstr_fd("\n", 2);
}

void	display_bench(t_ctx **ctx, t_stack **a)
{
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("+--------------------------------------------------+\n", 2);
	ft_putstr_fd("|                  PUSH_SWAP BENCH                 |\n", 2);
	ft_putstr_fd("+--------------------------------------------------+\n", 2);
	ft_putstr_fd("| Algorithm    : ", 2);
	ft_putstr_fd(disp_algo(ctx), 2);
	ft_putstr_fd("\n", 2);
	if (a && *a)
	{
		ft_putstr_fd("| Input size   : ", 2);
		ft_putnbr_fd((int)(*a)->size, 2);
		ft_putstr_fd("\n", 2);
	}
	print_disorder(ctx);
	ft_putstr_fd("| Total ops    : ", 2);
	ft_putnbr_fd(total_ops(ctx), 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("+--------------------------------------------------+\n", 2);
	print_ops_table(ctx);
	ft_putstr_fd("+--------------------------------------------------+\n", 2);
}
