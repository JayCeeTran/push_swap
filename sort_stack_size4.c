/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_size4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:10:02 by jtran             #+#    #+#             */
/*   Updated: 2025/01/13 08:46:50 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_size4(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_b, stack_a);
	sort_stack_size3(stack_a);
	if ((*stack_b)->val < (*stack_a)->val)
		push_a(stack_a, stack_b);
	else if ((*stack_b)->val > (*stack_a)->val
		&& (*stack_b)->val < (*stack_a)->next->val)
	{
		rotate_a(stack_a, 1);
		push_a(stack_a, stack_b);
		rr_a(stack_a, 1);
	}
	else if ((*stack_b)->val > (*stack_a)->next->val
		&& (*stack_b)->val < (*stack_a)->next->next->val)
	{
		rr_a(stack_a, 1);
		push_a(stack_a, stack_b);
		rotate_a(stack_a, 1);
		rotate_a(stack_a, 1);
	}
	else if ((*stack_b)->val > (*stack_a)->next->next->val)
	{
		push_a(stack_a, stack_b);
		rotate_a(stack_a, 1);
	}
}
