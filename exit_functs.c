/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:10:19 by jtran             #+#    #+#             */
/*   Updated: 2025/01/13 08:10:21 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	malloc_failed(t_stack *stack, char **temp)
{
	if (temp)
		freetemp(temp);
	ft_lstclear_ps(&stack);
	ft_printf("Error: Malloc failed!");
	exit(0);
}

void	invalid_argument(t_stack *stack, char **temp)
{
	if (temp)
		freetemp(temp);
	ft_lstclear_ps(&stack);
	ft_printf("Error: Invalid argument!");
	exit(0);
}
