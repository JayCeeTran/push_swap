#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_info{
	int target;
	int asize;
	int ctarget;
	int cmove;
	int moving_node;
}	t_info;

typedef struct s_stack{
	int val;
	int max;
	int min;
	int moves;
	int index;
	int lsize;
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

void	swap_a(t_stack **stack, int print);
void	swap_b(t_stack **stack, int print);
void	swap_ss(t_stack **stack_a, t_stack **stack_b);
void    push_a(t_stack **stack_a, t_stack **stack_b);
void    push_b(t_stack **stack_b, t_stack **stack_a);
void	rr_a(t_stack **stack, int print);
void	rr_b(t_stack **stack, int print);
void	rr_rr(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack, int print);
void	rotate_b(t_stack **stack, int print);
void	rotate_rr(t_stack **stack_a, t_stack **stack_b);

int	stack_in_order(t_stack *stack_a);
int	stack_in_rorder(t_stack *stack_a);
void	update_index(t_stack **stack);
void	max_val(t_stack **stack_a);
void    min_val(t_stack **stack_b);
void	min_to_head(t_stack **stack_a);
void    max_to_head(t_stack **stack_b);

int	find_position(t_stack *stack_a, t_stack *stack_b);
int	rotation(int index, int lsize);
int	possible_double_rotation(t_stack *stack_a, t_stack *stack_b);

int	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_stack_size5(t_stack **stack_a, t_stack **stack_b);
void	sort_stack_size4(t_stack **stack_a, t_stack **stack_b);
void	sort_stack_size3(t_stack **stack_a);
void	sortcase1(t_stack **stack_a);
void	sortcase2(t_stack **stack_a);
void	sortcase3(t_stack **stack_a);
void	sortcase4(t_stack **stack_a);
void	sortcase5(t_stack **stack_a);

void	main_sorting(t_stack **stack_a, t_stack **stack_b);
void	find_target_move_node(t_stack **stack_a, t_stack **stack_b);
void	move_node(t_stack **stack_a, t_stack ** stack_b, t_info data);
void	push_2nodes(t_stack **stack_a, t_stack **stack_b);

//MOVING NODE FUNCTIONS

void    rotate_both_then_1(t_stack **stack_a, t_stack **stack_b, t_info data);
void    rotate_a_rr_b(t_stack **stack_a, t_stack **stack_b, t_info data);
void	rr_a_rotate_b(t_stack **stack_a, t_stack **stack_b, t_info data);
void    rotate_b_only(t_stack **stack_b, t_info data);
void    rrotate_push(t_stack **stack_a, t_stack **stack_b);


void	print_stack(t_stack *stack_a);

#endif
