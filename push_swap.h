
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
	int	ft_isdigit(int c);
	int	ft_atoi(const char *str);
	int	check (int argc, char **argv);

typedef struct s_stack {
	int				data;
	struct s_stack	*next;
} t_stack;

t_stack	*stack_init(int argc, char **argv);
int		is_sorted(t_stack *a);
int		is_final(t_stack *a);

void sort(t_stack *a, t_stack *b);

t_stack  *lstnew(int data);
void	lstadd_front(t_stack **lst, t_stack *new);
int	lstsize(t_stack *list);
t_stack	*lstlast(t_stack *list);
void	lstadd_back(t_stack **lst, t_stack *new);

void 	stack_printf(t_stack *a);

void	s(t_stack **a);
void	p(t_stack **src, t_stack **dst);

#endif