#include "push_swap.h"

void	rotate_a(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

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
	
}

void	rotate_b(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

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
	
}

void	rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b || !(*stack_a) || !(*stack_b))
        return ;
	if (!(*stack_a)->next || !(*stack_b)->next)
		return ;
	rotate_a(stack_a);
	rotate_b(stack_b);
}
