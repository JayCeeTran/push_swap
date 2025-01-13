/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_and_rr_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:10:41 by jtran             #+#    #+#             */
/*   Updated: 2025/01/13 08:10:43 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b_first;

	if (!stack_b || !(*stack_b))
		return ;
	b_first = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	if ((*stack_b))
		(*stack_b)->prev = NULL;
	b_first->next = (*stack_a);
	if ((*stack_a))
		(*stack_a)->prev = b_first;
	(*stack_a) = b_first;
	(*stack_a)->prev = NULL;
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*a_first;

	if (!stack_a || !(*stack_a))
		return ;
	a_first = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	if ((*stack_a))
		(*stack_a)->prev = NULL;
	a_first->next = (*stack_b);
	if ((*stack_b))
		(*stack_b)->prev = a_first;
	(*stack_b) = a_first;
	(*stack_b)->prev = NULL;
	ft_printf("pb\n");
}

void	rr_a(t_stack **stack, int print)
{
	t_stack	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = (*stack);
	while ((*stack)->next)
		(*stack) = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->next = first;
	(*stack)->prev = NULL;
	first->prev = (*stack);
	if (print)
		ft_printf("rra\n");
}

void	rr_b(t_stack **stack, int print)
{
	t_stack	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = (*stack);
	while ((*stack)->next)
		(*stack) = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->next = first;
	(*stack)->prev = NULL;
	first->prev = (*stack);
	if (print)
		ft_printf("rrb\n");
}

void	rr_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b || !(*stack_a) || !(*stack_b))
		return ;
	if (!(*stack_a)->next || !(*stack_b)->next)
		return ;
	rr_a(stack_a, 0);
	rr_b(stack_b, 0);
	ft_printf("rrr\n");
}
