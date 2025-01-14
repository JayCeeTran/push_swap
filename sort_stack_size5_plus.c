/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_size5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:10:02 by jtran             #+#    #+#             */
/*   Updated: 2025/01/13 08:45:05 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target(t_stack *stack_a, t_stack *stack_b)
{
	int		max;
	int		min;
	t_stack	*temp;

	update_index(&stack_b);
	max = stack_b->max;
	min = stack_b->min;
	temp = stack_b;
	while (temp && temp->next)
	{
		if (stack_a->val < min && min == temp->val)
			return (temp->index);
		else if (stack_a->val > temp->val && stack_a->val < temp->next->val)
			return (temp->index + 1);
		else if (stack_a->val > max && max == temp->val)
			return (temp->index + 1);
		temp = temp->next;
	}
	if (stack_a->val < min)
		return(stack_b->lsize);
	return (stack_b->lsize + 1);
}

void	min_to_head_helper(int index, int size, t_stack **stack_a)
{
	if (rotation(index, size) == 1)
	{
		while (index-- > 1)
			rotate_a(stack_a, 1);
	}
	else if (rotation(index, size) == -1)
	{
		while (index++ <= size)
			rr_a(stack_a, 1);
	}
}

void	min_to_head(t_stack **stack_a)
{
	t_stack	*temp;
	int		index;
	int		min;
	int		size;

	index = 1;
	size = (*stack_a)->lsize;
	min = (*stack_a)->min;
	temp = (*stack_a);
	while (temp)
	{
		if (min == temp->val)
		{
			index = temp->index;
			break ;
		}
		temp = temp->next;
	}
	min_to_head_helper(index, size, stack_a);
}

void    move_node2(t_stack **stack_b, t_stack **stack_a, t_info data)
{
    
    if (rotation(data.moving_node, data.asize) == rotation(data.ctarget,
            (*stack_a)->lsize))
        rotate_both_then_12(stack_b, stack_a, data);
    else if (rotation(data.moving_node, data.asize) == 1)
        rotate_a_rr_b2(stack_b, stack_a, data);
    else if (rotation(data.moving_node, data.asize) == -1)
        rr_a_rotate_b2(stack_b, stack_a, data);
    else if (rotation(data.moving_node, data.asize) == 0)
        rotate_b_only2(stack_a, data);

}

void    move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;
    t_info  data;

    min_val(stack_a);
    max_val(stack_a);
    temp = (*stack_b);
    data.cmove = 1000;
    data.asize = ((*stack_b)->lsize);
    while (temp)
    {
        data.target = find_target(temp, (*stack_a));
        temp->moves = moves_arithmetic(temp->index, data.asize, data.target, (*stack_a)->lsize);
        if (temp->moves < data.cmove)
        {
            data.ctarget = data.target;
            data.cmove = temp->moves;
            data.moving_node = temp->index;
        }
        temp = temp->next;
    }
    move_node2(stack_b, stack_a, data);
}
