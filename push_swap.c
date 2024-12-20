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
		return (0);
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
	push_a(&node, &nodeb);
	printf("SEPERATE\n");
	while(node)
	{
		printf("prev:%p		node: %p	\n", node->prev, node);
		printf("stack_a:%d	stack_b:%d\n", node->val, nodeb->val);
		nodeb = nodeb->next;
		node = node->next;
	}


	
	return(0);

}
