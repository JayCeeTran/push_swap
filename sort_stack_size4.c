#include "push_swap.h"

void	sort_stack_size4(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_b, stack_a);
	sort_stack_size3(stack_a);
	if((*stack_b)->val < (*stack_a)->val)
		push_a(stack_a, stack_b);
	else if((*stack_b)->val > (*stack_a)->val && (*stack_b)->val < (*stack_a)->next->val)
	{
		rotate_a(stack_a, 1);
		push_a(stack_a, stack_b);
		rr_a(stack_a, 1);
	}
	else if((*stack_b)->val > (*stack_a)->next->val && (*stack_b)->val < (*stack_a)->next->next->val)
	{
		rr_a(stack_a, 1);
		push_a(stack_a, stack_b);
		rotate_a(stack_a, 1);
		rotate_a(stack_a, 1);
	}
	else if((*stack_b)->val > (*stack_a)->next->next->val)
	{
		push_a(stack_a, stack_b);
		rotate_a(stack_a, 1);
	}
}

void	push_first(t_stack **stack_a, t_stack **stack_b)
{
	if((*stack_b)->val < (*stack_a)->val)
		push_a(stack_a, stack_b);
	else if((*stack_b)->val > (*stack_a)->val && (*stack_b)->val < (*stack_a)->next->val)
	{
		rotate_a(stack_a, 1);
		push_a(stack_a, stack_b);
	}
	else if((*stack_b)->val > (*stack_a)->next->val && (*stack_b)->val < (*stack_a)->next->next->val)
	{
		rr_a(stack_a, 1);
		push_a(stack_a, stack_b);
	}
	else if((*stack_b)->val > (*stack_a)->next->next->val)
		push_a(stack_a, stack_b);
}

int	find_target(t_stack **stack_a, t_stack **stack_b)
{
	int max;
	int min;
	t_stack *temp;

	update_index(stack_a);
	max_val(stack_a);
	min_val(stack_a);
	max = (*stack_a)->max;
	min = (*stack_a)->min;
	temp = (*stack_a);
	while(temp && temp->next)
	{
		if((*stack_b)->val < min && min == temp->val)
			return(temp->index);
		else if(!temp->next && (*stack_b)->val > temp->val && (*stack_b)->val < temp->next->val)
			return(temp->index + 1);
		else if((*stack_b)->val > max && max == temp->val)
			return (temp->index + 1);
		temp = temp->next;
	}
	return(temp->index + 1);
	
}

void    min_to_head(t_stack **stack_a)
{
    t_stack *temp;
    int index;
    int min;
    int size;

    size = (*stack_a)->lsize;
    min = (*stack_a)->min;
    temp = (*stack_a);
    while(temp)
    {
        if(min == temp->val)
        {
			index = temp->index;
			break;
		}
        temp = temp->next;
    }
    if(rotation(index, size) == 1)
    {
        while(index-- > 1)
            rotate_a(stack_a, 1);
    }
    else if(rotation(index, size) == -1)
    {
        while(index++ <= size)
            rr_a(stack_a, 1);
    }
}

void	sort_stack_size5(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	int size;

	push_2nodes(stack_a, stack_b);
	sort_stack_size3(stack_a);
	push_first(stack_a, stack_b);
	i = find_target(stack_a, stack_b);
	size = (*stack_a)->lsize;
	if(rotation(i, size) == 1)
	{
		while(i-- > 1)
			rotate_a(stack_a, 1);
	}
	else if(rotation(i, size) == -1)
	{
		while(i++ <= size)
			rr_a(stack_a, 1);
	}
	push_a(stack_a, stack_b);
	update_index(stack_a);
	min_val(stack_a);
	min_to_head(stack_a);
}
