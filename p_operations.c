#include "push_swap.h"

void	push_a(t_stack **stack_b, t_stack **stack_a)
{
	t_stack *b_temp;
	t_stack *a_temp;

	b_temp = (*stack_b)->next;
	if (!stack_b || !(*stack_b))
		return ;
	a_temp = (*stack_b);
	(*stack_b) = b_temp;
	(*stack-b)->prev = NULL;
	a_temp->next = (*stack_a);
}
