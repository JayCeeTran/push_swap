#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{


	t_stack *stack_a;
	t_stack *stack_b;
	
	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = parse_argv_to_stack(argc - 1, argv + 1);

	(void)stack_b;
	(void)stack_a;
	return(0);

}
