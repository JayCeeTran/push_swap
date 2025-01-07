#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{


	t_stack *stack_a;
	
	if (argc < 2)
		return (0);
	stack_a = parse_argv_to_stack(argc - 1, argv + 1);

	return(0);

}
