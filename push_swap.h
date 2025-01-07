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

t_stack *parse_argv_to_stack(int argc, char **argv);
void	freetemp(char **temp);

void	malloc_failed(t_stack *stack, char **temp);
void	invalid_argument(t_stack *stack, char **temp);

void	swap_a(t_stack **stack);
void	swap_b(t_stack **stack);
void	swap_ss(t_stack **stack_a, t_stack **stack_b);
void    push_a(t_stack **stack_a, t_stack **stack_b);
void    push_b(t_stack **stack_b, t_stack **stack_a);
void	rr_a(t_stack **stack);
void	rr_b(t_stack **stack);
void	rr_rr(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	rotate_rr(t_stack **stack_a, t_stack **stack_b);


#endif
