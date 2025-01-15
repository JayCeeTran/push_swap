/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:10:23 by jtran             #+#    #+#             */
/*   Updated: 2025/01/15 07:41:53 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew_ps(int content)
{
	t_stack	*newnode;

	newnode = malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->val = content;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	current = *lst;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		while (current->next)
		{
			current = current->next;
		}
		current->next = new;
		new->prev = current;
	}
}

void	ft_lstclear_ps(t_stack **lst)
{
	t_stack	*temp;

	if (!*lst || !lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		(*lst) = (*lst)->next;
		free(temp);
	}
}
