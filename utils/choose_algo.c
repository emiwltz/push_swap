


#include "libft/includes/libft.h"
#include "push_swap.h"
void choose_algo(t_stack **a, t_stack **b, t_ctx *ctx)
{
  if (!compute_disorder(*a))
  {
    ft_printf("Nothing to do !\n");
    return ;
  }
  if(ctx->algo == ALGO_SIMPLE)
    selection(a,b, ctx);
  else if(ctx->algo == ALGO_MEDIUM)
    chunk_based(a,b, ctx);
  else if(ctx->algo == ALGO_COMPLEX)
     radix(a,b, ctx);
  else if(ctx->algo == ALGO_UNSET || ctx->algo == ALGO_ADAPTIVE)
  ft_printf("%i\n", compute_disorder(*a));
  {
    if(compute_disorder(*a) < 2000)
      selection(a,b, ctx);
    else if(compute_disorder(*a) >= 2000 && compute_disorder(*a) <= 5000)
      chunk_based(a,b, ctx);
    else
      radix(a,b, ctx);
  }
  if (ctx->bench_enabled == 1)
    display_bench(&ctx, a);
}
