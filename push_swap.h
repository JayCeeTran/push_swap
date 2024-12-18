#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct{
	int val;
	struct stack *next;
	struct stack *prev;
} stack;

void    ft_lstclear_ps(stack **lst, void (*del)(void *));
void    ft_lstadd_front_ps(stack **lst, stack *new);
void    ft_lstadd_back_ps(stack **lst, stack *new);
stack  *ft_lstnew_ps(void *content);
stack  *ft_lstlast_ps(stack *lst);
void    ft_lstiter_ps(stack *lst, void (*f)(void *));
stack  *ft_lstmap_ps(stack *lst, void *(*f)(void *), void (*del)(void *));
int     ft_lstsizei_ps(stack *lst);

#endif
