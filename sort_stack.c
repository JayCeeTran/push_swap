/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:11:40 by jtran             #+#    #+#             */
/*   Updated: 2025/01/15 08:27:40 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	update_index(stack_a);
	if (stack_in_order((*stack_a)))
		return (1);
	if ((*stack_a)->lsize == 2 && stack_in_rorder(*stack_a))
		swap_a(stack_a, 1);
	else if ((*stack_a)->lsize == 3)
		sort_stack_size3(stack_a);
	else if ((*stack_a)->lsize == 4)
		sort_stack_size4(stack_a, stack_b);
	else if (!stack_in_order((*stack_a)))
		main_sorting(stack_a, stack_b);
	return (1);
}

void	sort_stack_size3(t_stack **stack_a)
{
	int	node1;
	int	node2;
	int	node3;

	node1 = (*stack_a)->val;
	node2 = (*stack_a)->next->val;
	node3 = (*stack_a)->next->next->val;
	if (node1 < node3 && node3 < node2)
		sortcase1(stack_a);
	else if (stack_in_rorder((*stack_a)))
		sortcase2(stack_a);
	else if (node1 > node3 && node2 < node3)
		sortcase3(stack_a);
	else if (node1 > node2 && node1 < node3)
		sortcase4(stack_a);
	else if (node1 < node2 && node1 > node3)
		sortcase5(stack_a);
}

void	push_2nodes(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_b, stack_a);
	push_b(stack_b, stack_a);
	update_index_2(stack_a, stack_b);
}

void	main_sorting(t_stack **stack_a, t_stack **stack_b)
{
	push_2nodes(stack_a, stack_b);
	while ((stack_a && (*stack_a)) || ((*stack_b) && stack_b))
	{
		if ((*stack_a)->lsize == 3)
			break ;
		find_target_move_node(stack_a, stack_b);
		push_b(stack_b, stack_a);
		update_index_2(stack_a, stack_b);
	}
	sort_stack_size3(stack_a);
	update_index(stack_a);
	while (stack_b && (*stack_b))
	{
		move_stack_b_to_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
		update_index_2(stack_a, stack_b);
	}
	min_val(stack_a);
	min_to_head(stack_a);
}
