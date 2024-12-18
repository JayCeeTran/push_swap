#include "push_swap.h"

void	freetemp(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

void	add_argu_to_stack_then_free(stack **stack, char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		ft_lstadd_back_ps(stack, ft_lstnew_ps(ft_atoi(temp[i])));
		i++;
	}
	freetemp(temp);
}

stack	*parse_argv_to(int argcc, char **arg)
{
	/*//stack *stack;
	int	i;
	char	**temp;

	temp = ft_split("hello", ' ');
	///stack = NULL;
	i = 0;
	while(argcc-- > i)
	{
		printf("WORLD %s", temp[i]);
		//temp = ft_split(arg[i++], ' ');
		//add_argu_to_stack_then_free(&stack, temp);
	}
	arg++;*/
	arg++;
	argcc++;
	printf("Hello WORLD");
	return (NULL);
}



