/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:05:21 by bsarai            #+#    #+#             */
/*   Updated: 2022/02/21 12:05:23 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack {
	int				data;
	// int				ascore;
	// int				bscore;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks {
	struct s_stack	*a;
	struct s_stack	*b;

}	t_stacks;

typedef struct s_arr {
	int	*arr;
	int	len;
}	t_arr;

int			ft_isdigit(int c);
int			ft_atoi(const char *str, ...);
void		check(int argc, char **argv);

t_stacks	*stacks_init(int argc, char **argv);
void		free_stacks(t_stacks *stacks);

void		parse(t_stacks *stacks);
char		*ft_strstr(const char *haystack, const char *needle);
int			is_final(t_stack *a);

t_stack		*lstnew(int data);
void		lstadd_front(t_stack **lst, t_stack *new);
int			lstsize(t_stack *list);
t_stack		*lstlast(t_stack *list);
void		lstadd_back(t_stack **lst, t_stack *new);

void		stack_printf(t_stack *a);
void		stacks_printf(t_stack *a, t_stack *b);

void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);
#endif
