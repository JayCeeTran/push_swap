#include "push_swap.c"

stack  *ft_lstnew_ps(void *content)
{
        stack  *newnode;

        newnode = malloc(sizeof(stack));
        if (!newnode)
                return (NULL);
        newnode->content = content;
        newnode->next = NULL;
	newnode->prev = NULL;
        return (newnode);
}

void    ft_lstadd_back_ps(stack **lst, stack *new)
{
        stack  *current;

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

void    ft_lstadd_front_ps(stack **lst, stack *new)
{
        if (!new)
                return ;
        new->next = *lst;
        *lst = new;
}

void    ft_lstclear_ps(stack **lst, void (*del)(void *))
{
        stack  *temp;

        if (!*lst || !del || !lst)
                return ;
        while (*lst)
        {
                temp = *lst;
                (*lst) = (*lst)->next;
                del(temp->content);
                free(temp);
        }
}

stack  *ft_lstlast_ps(stack *lst)
{
        if (!lst)
                return (NULL);
        while (lst->next)
                lst = lst->next;
        return (lst);
}

