
#include "libft/includes/libft.h"
#include "push_swap.h"

char* disp_algo(t_ctx **ctx)
{
  if((*ctx)->algo == ALGO_SIMPLE)
    return ("Simple: [rajouter graph]");
  else if((*ctx)->algo == ALGO_MEDIUM)
    return ("Medium: [rajouter graph]");
  else if((*ctx)->algo == ALGO_COMPLEX)
    return ("Complex: [rajouter graph]");
  else if((*ctx)->algo == ALGO_ADAPTIVE)
    return ("Adaptive: [rajouter graph]");
  return ("Unset: [rajouter graph]");
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

void  display_bench(t_ctx **ctx, t_stack **a)
{
  ft_printf("--------------[BENCH]------------\n");
  ft_printf("%s\n", disorder_percentage(a));
  ft_printf("--------------[BENCH]------------\n");
  ft_printf("ALGO -> %s\n", disp_algo(ctx));
  ft_printf("TOTAL_OPS -> %i\n", total_ops(ctx));
}
