#include "push_swap.c"

void    ft_lstiter_ps(stack *lst, void (*f)(void *))
{
        if (!lst || !f)
                return ;
        while (lst)
        {
                f(lst->content);
                lst = lst->next;
        }
}

stack  *ft_lstmap_ps(stack *lst, void *(*f)(void *), void (*del)(void *))
{
        stack  *node;
        stack  *new_lst;

        new_lst = NULL;
        if (!lst || !f || !del)
                return (NULL);
        while (lst)
        {
                node = ft_lstnew_ps(f(lst->content));
                if (!node)
                {
                        ft_lstclear_ps(&new_lst, del);
                        return (NULL);
                }
                ft_lstadd_back_ps(&new_lst, node);
                lst = lst->next;
        }
        return (new_lst);
}

int     ft_lstsizei_ps(stack *lst)
{
        int     i;

        i = 0;
        while (lst)
        {
                i++;
                lst = lst->next;
        }
        return (i);
}

