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

void	update_index(t_stack **stack_a)
{
	int	i;
	t_stack *temp;

	i = 1;
	temp = (*stack_a);
	while(temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
	(*stack_a)->lsize = i - 1;
}

void	fill_struct_info(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("here\n");
	update_index(stack_a);
	update_index(stack_b);
	printf("a: %d	b: %d\n", (*stack_a)->lsize, (*stack_b)->lsize);
	//count_moves(stack_a, stack_b);
}
