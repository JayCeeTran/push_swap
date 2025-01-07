#include "push_swap.h"

int	count_moves(t_stack *stack_a, t_stack *stack_b)
{
	if(valid_push(stack_a))
		return(1);
	while(stack_b && stack_b->next)
	{
		if(stack_a->val < stack_b->val && stack_a->val > stack_b->next->val)
			break;
		stack_b = stack_b->next;
	}
}
