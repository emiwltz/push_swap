

#include "push_swap.h"
#include <stddef.h>

int get_sqrt(size_t size)
{
  size_t sqrt;

  if (size < 1)
    return (1);
  sqrt = 1;
  while ((long)sqrt * (long)sqrt < (long)size)
  {
    sqrt++;
  }
  return (sqrt);
}



void  chunk_based(t_stack **a, t_stack **b, t_ctx *ctx)
{
  size_t  chunk_size;
  size_t  chunk_min;
  size_t  chunk_max;
  size_t  chunk_count;

  chunk_size = get_sqrt((*a)->size) / (*a)->size;
  chunk_min = 0;
  chunk_max = chunk_size;
  while (!check_rank(a))
  {
    chunk_count = 0;
    while (chunk_count <= chunk_size)
    {
      if ((*a)->head->rank > chunk_min && (*a)->head->rank < chunk_max)
      {
        pb(a, b, ctx);
        chunk_count++;
      }
      else
        ra(a, ctx);
    }
    while ((*b))
      pa(b, a, ctx);
  }
}
