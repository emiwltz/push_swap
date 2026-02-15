
#include "libft/includes/libft.h"
#include "push_swap.h"

void  display_bench(t_ctx **ctx, t_stack **a)
{
  ft_printf("--------------[BENCH]------------\n");
  ft_printf("%s\n", disorder_percentage(a));
  ft_printf("--------------[BENCH]------------\n");
  ft_printf("%i\n", (*ctx)->algo);
}
