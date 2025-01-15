/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_size3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:11:29 by jtran             #+#    #+#             */
/*   Updated: 2025/01/15 07:26:31 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortcase1(t_stack **stack_a)
{
	swap_a(stack_a, 1);
	rotate_a(stack_a, 1);
}

void	sortcase2(t_stack **stack_a)
{
	swap_a(stack_a, 1);
	rr_a(stack_a, 1);
}

void	sortcase3(t_stack **stack_a)
{
	rotate_a(stack_a, 1);
}

void	sortcase4(t_stack **stack_a)
{
	swap_a(stack_a, 1);
}

void	sortcase5(t_stack **stack_a)
{
	rr_a(stack_a, 1);
}
