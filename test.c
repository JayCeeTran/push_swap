#include "push_swap.h"
#include <stdio.h>

int     main(int argc, char **argv)
{

        t_stack *stack_a;
        t_stack *node;
        t_stack *stack_b;

	stack_b = NULL;
        int i;

        i = 0;
        if (argc < 2)
                return (0);
        stack_a = parse_argv_to_stack(argc - 1, argv + 1);
        node = stack_a;
        while(stack_a)
        {
                printf("a: %d\n", stack_a->val);
                stack_a = stack_a->next;
                
        }
	update_index(&node);
        printf("SEPERATE\n");
	sort_stack(&node, &stack_b);

        while(node)
        {
                //printf("prev:%p         node: %p        index: %d\n", node->prev, node, node->index);
                printf("stack_a:%d      index: %d\n", node->val, node->index);
                
                node = node->next;
	}
	return(0);

}

