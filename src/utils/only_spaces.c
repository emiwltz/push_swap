

#include "libft.h"
#include "push_swap.h"

int only_spaces(char *s)
{
  int i;

  i = 0;
  while (s[i])
  {
    if (s[i] != ' ')
      return (0);
    i++;
  }
  return (1);
}
