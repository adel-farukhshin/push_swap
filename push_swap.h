
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
	int	ft_isdigit(int c);
	int	ft_atoi(const char *str);
	int	check (int argc, char **argv);

typedef struct s_stack {
	void			*data;
	struct s_list	*next;
} t_stack;


#endif