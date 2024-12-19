#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{

	t_stack *stack_a;
	t_stack *node;
	int i;
							
	i = 0;
	if (argc < 2)
		return (0);
	stack_a = parse_argv_to(--argc, ++argv);
	node = stack_a;
	while(stack_a)
	{
		printf("%d\n", stack_a->val);
		stack_a = stack_a->next;
	}
	ft_lstclear_ps(&node);


	
	return(0);

}
