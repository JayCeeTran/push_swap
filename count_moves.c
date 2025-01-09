#include "push_swap.h"

int	find_position(t_stack *stack_a, t_stack *stack_b)
{
	int lastindex = stack_b->lsize;
	if(!stack_a || !stack_b)
		return(0);
	while(stack_b)
	{
		if(stack_a->val > stack_b->val)
			return(stack_b->index);
		stack_b = stack_b->next;
	}
	return(lastindex + 1);
}

int	way_of_rotation(int index, int lsize)
{
	if(lsize - index >= index)
		return(1);
	else
		return (-1);
}

int	moves_arithmetic(int index, int asize, int target, int bsize)
{
	int moves;

	moves = 0;
	if(way_of_rotation(index, asize) == way_of_rotation(target, bsize))
	{
		if(index > target)
			return(index + 1);
		else
			return(target + 1);
	}
	if(way_of_rotation(index, asize) == 1)
		moves += index;
	else
		moves += asize - index + 1;
	if(way_of_rotation(target, bsize) == 1)
		moves += target;
	else
		moves += bsize - target + 1;
	return(moves + 1);
}

void	count_moves(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp = (*stack_a);
	int target;
	int asize;
	
	asize = ((*stack_a)->lsize);
	while(temp)
	{
		target = find_position(temp, (*stack_b));
		temp->moves = moves_arithmetic(temp->index, asize, target, (*stack_b)->lsize);
		temp = temp->next;
	}	
}
