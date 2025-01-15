/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:10:19 by jtran             #+#    #+#             */
/*   Updated: 2025/01/15 09:51:34 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_stack(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	malloc_failed(t_stack *stack, char **temp)
{
	if (temp)
		freetemp(temp);
	ft_lstclear_ps(&stack);
	write(2, "Error\n", 6);
	exit(1);
}

void	invalid_argument(t_stack *stack, char **temp)
{
	if (temp)
		freetemp(temp);
	ft_lstclear_ps(&stack);
	write(2, "Error\n", 6);
	exit(1);
}
