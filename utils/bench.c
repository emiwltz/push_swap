/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:02:50 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/16 14:26:36 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/includes/libft.h"
#include "push_swap.h"

static char	*disp_algo(t_ctx **ctx)
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

static int	total_ops(t_ctx **ctx)
{
	int	total_ops;

	total_ops = (*ctx)->pa_count + (*ctx)->pb_count;
	total_ops += (*ctx)->ra_count + (*ctx)->rb_count + (*ctx)->rr_count;
	total_ops += (*ctx)->rra_count + (*ctx)->rrb_count + (*ctx)->rrr_count;
	total_ops += (*ctx)->sa_count + (*ctx)->sb_count + (*ctx)->ss_count;
	return (total_ops);
}

static void	print_disorder(t_ctx **ctx)
{
	int	disorder;

	disorder = (*ctx)->disorder;
	ft_printf("| Disorder     : %i.", disorder / 100);
	if (disorder % 100 < 10)
		ft_printf("0");
	ft_printf("%i%%\n", disorder % 100);
}

static void	print_ops_table(t_ctx **ctx)
{
	ft_printf("		+-----+\n");
	ft_printf("		| OPS |\n");
	ft_printf("		+-----+\n\n");
	ft_printf("| push       : pa=%i  pb=%i\n", (*ctx)->pa_count, (*ctx)->pb_count);
	ft_printf("| rotate     : ra=%i  rb=%i  rr=%i\n", (*ctx)->ra_count,
		(*ctx)->rb_count, (*ctx)->rr_count);
	ft_printf("| rev_rotate : rra=%i rrb=%i rrr=%i\n", (*ctx)->rra_count,
		(*ctx)->rrb_count, (*ctx)->rrr_count);
	ft_printf("| swap       : sa=%i  sb=%i  ss=%i\n", (*ctx)->sa_count,
		(*ctx)->sb_count, (*ctx)->ss_count);
}

/*
** Backup old version:
** void	display_bench(t_ctx **ctx, t_stack **a)
** {
** 	(void)a;
** 	ft_printf("--------------[BENCH]------------\n");
** 	ft_printf("DISORDER: %s%%\n", disorder_percentage(**ctx));
** 	ft_printf("ALGO -> %s\n", disp_algo(ctx));
** 	ft_printf("TOTAL_OPS -> %i\n", total_ops(ctx));
** 	print_ops(ctx);
** }
*/

void	display_bench(t_ctx **ctx, t_stack **a)
{
	ft_printf("\n");
	ft_printf("+--------------------------------------------------+\n");
	ft_printf("|                  PUSH_SWAP BENCH                 |\n");
	ft_printf("+--------------------------------------------------+\n");
	ft_printf("| Algorithm    : %s\n", disp_algo(ctx));
	if (a && *a)
		ft_printf("| Input size   : %i\n", (int)(*a)->size);
	print_disorder(ctx);
	ft_printf("| Total ops    : %i\n", total_ops(ctx));
	ft_printf("+--------------------------------------------------+\n");
	print_ops_table(ctx);
	ft_printf("+--------------------------------------------------+\n");
}
