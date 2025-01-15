/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:11:45 by jtran             #+#    #+#             */
/*   Updated: 2025/01/15 07:43:49 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_in_order(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->val > stack_a->next->val)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	stack_in_rorder(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->val < stack_a->next->val)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	update_index(t_stack **stack_a)
{
	int		i;
	t_stack	*temp;

	if (stack_a && (*stack_a))
	{
		i = 1;
		temp = (*stack_a);
		while (temp)
		{
			temp->index = i;
			temp = temp->next;
			i++;
		}
		(*stack_a)->lsize = i - 1;
	}
}

void	max_val(t_stack **stack_a)
{
	int		max_val;
	t_stack	*temp;

	temp = (*stack_a);
	max_val = (*stack_a)->val;
	while (temp)
	{
		if (temp->val > max_val)
			max_val = temp->val;
		temp = temp->next;
	}
	(*stack_a)->max = max_val;
}

void	min_val(t_stack **stack_b)
{
	int		min;
	t_stack	*temp;

	temp = (*stack_b);
	min = (*stack_b)->val;
	while (temp)
	{
		if (temp->val < min)
			min = temp->val;
		temp = temp->next;
	}
	(*stack_b)->min = min;
}
