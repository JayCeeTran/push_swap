/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:55:36 by jtran             #+#    #+#             */
/*   Updated: 2025/01/15 07:42:02 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_help(t_stack **stack_a, t_stack **stack_b, t_info data, int size)
{
	while (data.moving_node <= data.asize && data.ctarget <= size)
	{
		rr_rr(stack_a, stack_b);
		data.ctarget++;
		data.moving_node++;
	}
	while (data.ctarget++ <= size)
		rr_b(stack_b, 1);
	while (data.moving_node++ <= data.asize)
		rr_a(stack_a, 1);
}

void	rotate_both_then_1(t_stack **stack_a, t_stack **stack_b, t_info data)
{
	int	size;

	size = (*stack_b)->lsize;
	if (rotation(data.ctarget, size) == 1)
	{
		while (data.ctarget > 1 && data.moving_node > 1)
		{
			rotate_rr(stack_a, stack_b);
			data.ctarget--;
			data.moving_node--;
		}
		while (data.ctarget-- > 1)
			rotate_b(stack_b, 1);
		while (data.moving_node-- > 1)
			rotate_a(stack_a, 1);
	}
	else if (rotation(data.ctarget, size) == -1)
		rotate_help(stack_a, stack_b, data, size);
}

void	rotate_a_rr_b(t_stack **stack_a, t_stack **stack_b, t_info data)
{
	int	size;

	size = (*stack_b)->lsize;
	while (data.moving_node-- > 1)
		rotate_a(stack_a, 1);
	while (data.ctarget <= size && rotation(data.ctarget, size) == -1)
	{
		data.ctarget++;
		rr_b(stack_b, 1);
	}
}

void	rr_a_rotate_b(t_stack **stack_a, t_stack **stack_b, t_info data)
{
	int	size;

	size = (*stack_b)->lsize;
	while (data.moving_node++ <= data.asize)
		rr_a(stack_a, 1);
	while (data.ctarget > 1 && rotation(data.ctarget, size) == 1)
	{
		data.ctarget--;
		rotate_b(stack_b, 1);
	}
}

void	rotate_b_only(t_stack **stack_b, t_info data)
{
	int	size;

	size = (*stack_b)->lsize;
	if (rotation(data.ctarget, size) == 1)
	{
		while (data.ctarget-- > 1)
			rotate_b(stack_b, 1);
	}
	else if (rotation(data.ctarget, size) == -1)
	{
		while (data.ctarget++ <= size)
		{
			rr_b(stack_b, 1);
		}
	}
}
