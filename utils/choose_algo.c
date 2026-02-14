


#include "push_swap.h"
void choose_algo(t_stack **a, t_stack **b, t_ctx *ctx)
{
  if(ctx->algo == ALGO_SIMPLE)
     selection(a,b, ctx);
  else if(ctx->algo == ALGO_MEDIUM)
     chunk_based(a,b, ctx);
  else if(ctx->algo == ALGO_COMPLEX)
     radix(a,b, ctx);
  else if(ctx->algo == ALGO_UNSET || ctx->algo == ALGO_ADAPTIVE)
  {
    if(compute_disorder(*a) < 0.2)
      selection(a,b, ctx);
    else if(compute_disorder(*a) >= 0.2 && compute_disorder(*a) <= 0.5)
      chunk_based(a,b, ctx);
    else
      radix(a,b, ctx);
  }
  // if (ctx->bench_enabled)
    // disp_bench();
}
