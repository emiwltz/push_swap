


#include "push_swap.h"
void choose_algo(t_stack **a, t_stack **b, t_ctx **ctx)
{
  if((*ctx)->algo == ALGO_SIMPLE)
     selection(a,b);
  else if((*ctx)->algo == ALGO_MEDIUM)
     chunk_based(a,b);
  else if((*ctx)->algo == ALGO_COMPLEX)
     radix(a,b);
  else if((*ctx)->algo == ALGO_UNSET || (*ctx)->algo == ALGO_ADAPTIVE)
  {
    if(compute_disorder(*a) < 0.2)
      selection(a,b);
    else if(compute_disorder(*a) >= 0.2 && compute_disorder(*a) <= 0.5)
      chunk_based(a,b);
    else
      radix(a,b);
  }
  // if ((*ctx)->bench_enabled)
    // disp_bench();
}
