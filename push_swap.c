/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:10:57 by jtran             #+#    #+#             */
/*   Updated: 2025/01/13 11:03:17 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	rotation(int index, int lsize)
{
	if (index == 1)
		return (0);
	if ((lsize + 1) / 2 >= index)
		return (1);
	else
		return (-1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	stack_a = parse_argv_to_stack(argc - 1, argv + 1);
	sort_stack(&stack_a, &stack_b);
	print_stack(stack_a);
	ft_lstclear_ps(&stack_a);
	return (0);
}
