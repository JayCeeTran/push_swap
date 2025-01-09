#include "push_swap.h"

int	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if(stack_in_order((*stack_a)))
		return (1);
	if((*stack_a)->lsize == 3)
		sort_stack_size3(stack_a);
	if(!stack_in_order((*stack_a)))
		main_sorting(stack_a, stack_b);

	return(1);	
}

void    sort_stack_size3(t_stack **stack_a)
{
        int node1 = (*stack_a)->val;
        int node2 = (*stack_a)->next->val;
        int node3 = (*stack_a)->next->next->val;

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
	if ((*stack_b)->val < (*stack_b)->next->val)
		swap_b(stack_b, 1);

	t_stack *temp = (*stack_b);
	while(temp)
	{
		ft_printf("%d b:\n", temp->val);
		temp = temp->next;
	}
}

void	main_sorting(t_stack **stack_a, t_stack **stack_b)
{
	push_2nodes(stack_a, stack_b);
	while(!stack_in_order((*stack_a)) || (*stack_b))
	{
		fill_struct_info(stack_a, stack_b);
		break;
	}
}


