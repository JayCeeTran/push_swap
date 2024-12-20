#include "push_swap.h"

void	validate_add_free(t_stack **stack, char **temp);
int	validate_argument(char *temp);
int	check_duplicates(t_stack *stack, t_stack *node);


t_stack	*parse_argv_to_stack(int argc, char **argv)
{
	t_stack *stack;
	int	i;
	char	**temp;

	stack = NULL;
	i = 0;
	while(argc-- > 0)
	{
		temp = ft_split(argv[i++], ' ');
		if(!temp)
			malloc_failed(stack, temp);
		validate_add_free(&stack, temp);
	}
	return (stack);
}

void	validate_add_free(t_stack **stack, char **temp)
{
	int	i;
	t_stack *newnode;

	i = 0;
	while (temp[i])
	{
		if (!validate_argument(temp[i]))
			invalid_argument(*stack, temp);
		newnode = ft_lstnew_ps(ft_atoi(temp[i]));
		if (!newnode)
			malloc_failed(*stack, temp);
		if(!check_duplicates(*stack, newnode))
		{
			free(newnode);
			invalid_argument(*stack, temp);
		}
		ft_lstadd_back_ps(stack, newnode);
		i++;
	}
	freetemp(temp);
}

int	validate_argument(char *temp)
{
	int i;
	long long val;

	val = 0;
	i = 0;
	while (temp[i])
	{
		if (temp[i] < '0' || temp[i] > '9')
			return (0);
		val = val * 10 + (temp[i] - '0');
		i++;
	}
	if (val > 2147483647 || val < -2147483648)
		return (0);
	return (1);
}

int	check_duplicates(t_stack *stack, t_stack *node)
{
	while (stack)
	{
		if (node->val == stack->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

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
