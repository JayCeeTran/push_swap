/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:11:14 by jtran             #+#    #+#             */
/*   Updated: 2025/01/13 08:11:26 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = (*stack);
	second = (*stack)->next;
	(*stack) = second;
	(*stack)->prev = NULL;
	while (second->next)
		second = second->next;
	second->next = first;
	first->prev = second;
	first->next = NULL;
	if (print)
		ft_printf("ra\n");
}

void	rotate_b(t_stack **stack, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = (*stack);
	second = (*stack)->next;
	(*stack) = second;
	(*stack)->prev = NULL;
	while (second->next)
		second = second->next;
	second->next = first;
	first->prev = second;
	first->next = NULL;
	if (print)
		ft_printf("rb\n");
}

void	rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b || !(*stack_a) || !(*stack_b))
		return ;
	if (!(*stack_a)->next || !(*stack_b)->next)
		return ;
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	ft_printf("rr\n");
}
