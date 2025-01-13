#include "push_swap.h"

int	find_position(t_stack *stack_a, t_stack *stack_b)
{
	int lastindex;
	int	max;
	int min;

	lastindex = stack_b->lsize;
	max = stack_b->max;
	min = stack_b->min;
	if(!stack_a || !stack_b)
		return(0);
	while(stack_b && stack_b->next)
	{
		if(stack_a->val > max && max == stack_b->val)
			return(stack_b->index);
		else if(stack_a->val < stack_b->val && stack_a->val > stack_b->next->val)
			return(stack_b->index + 1);
		else if (stack_a->val < min && min == stack_b->val)
			return (stack_b->index + 1);
		stack_b = stack_b->next;
	}
	if(stack_a->val > max)
		return(lastindex);
	return(lastindex + 1);
}

int	rotation(int index, int lsize)
{
	if (index == 1)
		return(0);
	if((lsize + 1 ) / 2 >= index)
		return(1);
	else
		return (-1);
}

int	moves_arithmetic(int index, int asize, int target, int bsize)
{
	int moves;

	moves = 0;
	if(index == 1 && target == 1)
		return(1);
	if(target > bsize && index == 1)
		return(2);
	if(rotation(index, asize) == rotation(target, bsize))
	{
		if(rotation(index, asize) == 1)
		{
			if(index >= target)
				return(index + 1);
			else
				return(target + 1);
		}
		else
		{	
			if(asize - index > bsize - target)
				return(bsize - target + 2);
			else if(asize - index <= bsize - target)
				return(asize - index + 2);
		}
	}
	if(rotation(index, asize) == 1)
		moves += index;
	else if (rotation(index, asize) == -1)
		moves += asize - index + 1;
	if(rotation(target, bsize) == 1)
		moves += target;
	else if (rotation(target, bsize) == -1)
		moves += bsize - target + 1;
	return(moves + 1);
}

void	move_node(t_stack **stack_a, t_stack **stack_b, t_info data)
{
	if(rotation(data.moving_node, data.asize) == rotation(data.ctarget, (*stack_b)->lsize))
		rotate_both_then_1(stack_a, stack_b, data);
	else if(rotation(data.moving_node, data.asize) == 1)
		rotate_a_rr_b(stack_a, stack_b, data);
	else if(rotation(data.moving_node, data.asize) == -1)
		rr_a_rotate_b(stack_a, stack_b, data);
	else if(rotation(data.moving_node, data.asize) == 0)
		rotate_b_only(stack_b, data);
	push_b(stack_b, stack_a);
	update_index(stack_a);
	update_index(stack_b);
}

void	find_target_move_node(t_stack **stack_a, t_stack **stack_b)
{
	min_val(stack_b);
	max_val(stack_b);
	t_stack *temp = (*stack_a);
	t_info data;

	data.cmove = 1000;
	data.asize = ((*stack_a)->lsize);
	while(temp)
	{
		data.target = find_position(temp, (*stack_b));
		temp->moves = moves_arithmetic(temp->index, data.asize, data.target, (*stack_b)->lsize);
		if(temp->moves < data.cmove)
		{
			data.ctarget = data.target;
			data.cmove = temp->moves;
			data.moving_node = temp->index;
		}
		temp = temp->next;
	}
	move_node(stack_a, stack_b, data);	
}
