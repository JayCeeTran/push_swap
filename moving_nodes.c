#include "push_swap.h"

void	print_stack(t_stack *stack_a)
{
	while(stack_a)
	{
		printf("stack_b: %d	index:%d\n", stack_a->val, stack_a->index);
		stack_a = stack_a->next;
	}
}

void	max_to_head(t_stack **stack_b)
{
	t_stack *temp;
	int	index;
	int max;
	int size;

	size = (*stack_b)->lsize;
	max = (*stack_b)->max;
	temp = (*stack_b);
	while(temp)
	{
		if(max == temp->val)
		{
			index = temp->index;
			break;
		}
		temp = temp->next;
	}
	if(rotation(index, size) == 1)
	{
		while(index-- > 1)
			rotate_b(stack_b, 1);
	}
	else if(rotation(index, size) == -1)
	{
		while(index++ <= size)
			rr_b(stack_b, 1);
	}

}

void	rotate_both_then_1(t_stack **stack_a, t_stack **stack_b, t_info data)
{
	int size;

	size = (*stack_b)->lsize;
	if(rotation(data.ctarget, size) == 1)
	{
		while(data.ctarget > 1 && data.moving_node > 1)
		{
			rotate_rr(stack_a, stack_b);
			data.ctarget--;
			data.moving_node--;
		}
		while(data.ctarget-- > 1)
			rotate_b(stack_b, 1);
		while(data.moving_node-- > 1)
			rotate_a(stack_a, 1);
	}
	else if (rotation(data.ctarget, size) == -1)
	{	
		while(data.moving_node <= data.asize && data.ctarget <= size)
		{	
			rr_rr(stack_a, stack_b);
			data.ctarget++;
			data.moving_node++;
		}
		while(data.ctarget++ <= size)
			rr_b(stack_b, 1);
		while(data.moving_node++ <= data.asize)
			rr_a(stack_a, 1);
	}
}

void	rotate_a_rr_b(t_stack **stack_a, t_stack **stack_b, t_info data)
{
		int size;

		size = (*stack_b)->lsize;
		while(data.moving_node-- > 1)
			rotate_a(stack_a, 1);
		if(data.ctarget == 1)
			return;
		while(data.ctarget++ <= size)
			rr_b(stack_b, 1);	
}

void	rr_a_rotate_b(t_stack **stack_a, t_stack **stack_b, t_info data)
{
		while(data.moving_node++ <= data.asize)
            rr_a(stack_a, 1);
		if(data.ctarget == 1)
			return;
        while(data.ctarget-- > 1)
            rotate_b(stack_b, 1);
}

void	rotate_b_only(t_stack **stack_b, t_info data)
{
	int size;

	size = (*stack_b)->lsize;
	if(rotation(data.ctarget, size) == 1)
	{
		while(data.ctarget-- > 1)
			rotate_b(stack_b, 1);
	}
	else if(rotation(data.ctarget, size) == -1)
	{
		while(data.ctarget++ <= size)
		{
			rr_b(stack_b, 1);
		}
	}
}
