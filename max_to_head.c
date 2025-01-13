/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_to_head.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:55:36 by jtran             #+#    #+#             */
/*   Updated: 2025/01/13 10:14:10 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack_a)
{
	while (stack_a)
	{
		printf("stack_b: %d	index:%d\n", stack_a->val, stack_a->index);
		stack_a = stack_a->next;
	}
}

void	max_to_head_helper(int index, int size, t_stack **stack_b)
{
	if (rotation(index, size) == 1)
	{
		while (index-- > 1)
			rotate_b(stack_b, 1);
	}
	else if (rotation(index, size) == -1)
	{
		while (index++ <= size)
			rr_b(stack_b, 1);
	}
}

void	max_to_head(t_stack **stack_b)
{
	t_stack	*temp;
	int		index;
	int		max;
	int		size;

	index = 1;
	size = (*stack_b)->lsize;
	max = (*stack_b)->max;
	temp = (*stack_b);
	while (temp)
	{
		if (max == temp->val)
		{
			index = temp->index;
			break ;
		}
		temp = temp->next;
	}
	max_to_head_helper(index, size, stack_b);
}
