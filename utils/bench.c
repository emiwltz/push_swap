/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:02:50 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/16 11:47:58 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/includes/libft.h"
#include "push_swap.h"

char* disp_algo(t_ctx **ctx)
{
  if((*ctx)->algo == ALGO_SIMPLE)
    return ("Simple: O(n²)");
  else if((*ctx)->algo == ALGO_MEDIUM)
    return ("Medium: O(n√n)");
  else if((*ctx)->algo == ALGO_COMPLEX)
    return ("Complex: [rajouter graph]");
  else if((*ctx)->algo == ALGO_ADAPTIVE)
    return ("Adaptive: O(n log n)");
  return ("Unset");
}

int total_ops(t_ctx **ctx)
{
  int total_ops;

  total_ops = (*ctx)->pa_count + (*ctx)->pb_count;
  total_ops += (*ctx)->ra_count + (*ctx)->rb_count + (*ctx)->rr_count;
  total_ops += (*ctx)->rra_count + (*ctx)->rrb_count + (*ctx)->rrr_count;
  total_ops += (*ctx)->sa_count + (*ctx)->sb_count + (*ctx)->ss_count;
  return (total_ops);
}

void	print_ops(t_ctx **ctx)
{
  ft_printf("--------------------\n");
  ft_printf("pa: %i   ", (*ctx)->pa_count);
  ft_printf("pb: %i   \n", (*ctx)->pb_count);
  ft_printf("--------------------\n");
  ft_printf("ra: %i   ", (*ctx)->ra_count);
  ft_printf("rb: %i   ", (*ctx)->rb_count);
  ft_printf("rr: %i  \n", (*ctx)->rr_count);
  ft_printf("--------------------\n");
  ft_printf("rra:%i   ", (*ctx)->rra_count);
  ft_printf("rrb:%i   ", (*ctx)->rrb_count);
  ft_printf("rrr:%i   \n", (*ctx)->rrr_count);
  ft_printf("--------------------\n");
  ft_printf("sa: %i   ", (*ctx)->sa_count);
  ft_printf("sb: %i   ", (*ctx)->sb_count);
  ft_printf("ss: %i   \n", (*ctx)->ss_count);
}

void  display_bench(t_ctx **ctx, t_stack **a)
{
  ft_printf("--------------[BENCH]------------\n");
  ft_printf("-------------[Disorder]----------\n");
  disorder_percentage(a);
  ft_printf("-------------[Disorder]----------\n");
  ft_printf("ALGO -> %s\n", disp_algo(ctx));
  ft_printf("TOTAL_OPS -> %i\n", total_ops(ctx));
  print_ops(ctx);
}
