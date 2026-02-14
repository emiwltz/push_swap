
#include "push_swap.h"

int	check_rank(t_stack **a)
{
	t_node	*node;

	if (!a || !(*a) || !(*a)->head || (*a)->size < 2)
		return (1);
	node = (*a)->head;
	while (node != (*a)->tail)
	{
		if (node->rank > node->next->rank)
			return (0);
		node = node->next;
	}
	return (1);
}
