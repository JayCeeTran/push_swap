#include "push_swap.c"


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

