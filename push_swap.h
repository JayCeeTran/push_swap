#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack{
	int val;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

void    ft_lstclear_ps(t_stack **lst);
void    ft_lstadd_front_ps(t_stack **lst, t_stack *new);
void    ft_lstadd_back_ps(t_stack **lst, t_stack *new);
t_stack  *ft_lstnew_ps(int content);
t_stack  *ft_lstlast_ps(t_stack *lst);
int     ft_lstsizei_ps(t_stack *lst);

t_stack *parse_argv_to(int argc, char **argv);
void	freetemp(char **temp);

void	malloc_failed(t_stack *stack, char **temp);
void	invalid_argument(t_stack *stack, char **temp);

#endif
