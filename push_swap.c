#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{

	t_stack *stack_a;
	t_stack *node;
	t_stack *nodeb;
	t_stack *stack_b;
	int i;
							
	i = 0;
	if (argc < 2)
		return (i);
	stack_b = parse_argv_to_stack(argc - 1, argv + 1);
	stack_a = parse_argv_to_stack(argc - 1, argv + 1);
	node = stack_a;
	nodeb = stack_b;
	while(stack_a)
	{
		printf("%d & %d\n", stack_a->val, stack_b->val);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
	rr_b(&nodeb);
	rotate_a(&node);
	rotate_rr(&nodeb, &node);
	rotate_a(&nodeb);
	printf("SEPERATE\n");
	while(nodeb)
	{
		printf("prev:%p		node: %p	next:%p\n", nodeb->prev, nodeb, nodeb->next);
		printf("stack_a:%d stack_b %d\n", nodeb->val, node->val);
		node = node->next;
		nodeb = nodeb->next;
		printf("Teeest");
		printf("its getting weird\n");
	}	
	return(0);

}
