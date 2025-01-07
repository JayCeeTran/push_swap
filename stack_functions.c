#include "push_swap.h"

int	stack_in_order(t_stack *stack_a)
{
	while(stack_a && stack_a->next)		
	{
		if(stack_a->val > stack_a->next->val)
			return(0);
		stack_a = stack_a->next;
	}
	return(1);
}

int     stack_in_rorder(t_stack *stack_a)
{
        while(stack_a && stack_a->next)
        {
                if(stack_a->val < stack_a->next->val)
                        return(0);
                stack_a = stack_a->next;
        }
        return(1);
}

int	valid_push(t_stack *stack_a, t_stack *stack_b)
{
	if(stack_a->val > stack_b->val)
		return(1);
	return(0);
}

void	update_index(t_stack *stack)
{
	int	i;
	t_stack *temp;

	i = 1;
	temp = stack;
	while(stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
	temp->lsize = i - 1;
}
