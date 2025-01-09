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

void sortcase4(t_stack **stack_a)
{
	swap_a(stack_a, 1);
}

void sortcase5(t_stack **stack_a)
{
	rr_a(stack_a, 1);
}
