#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct stacks{
	int val;
	struct stacks *next;
	struct stacks *prev;
} stack;

void    ft_lstclear_ps(stack **lst);
void    ft_lstadd_front_ps(stack **lst, stack *new);
void    ft_lstadd_back_ps(stack **lst, stack *new);
stack  *ft_lstnew_ps(int content);
stack  *ft_lstlast_ps(stack *lst);
int     ft_lstsizei_ps(stack *lst);

stack *parse_argv_to(int argcc, char **arg);

#endif
