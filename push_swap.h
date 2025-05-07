/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:28:46 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/04/29 12:28:53 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_stacks //stack w którym są 2 staki 
{
	t_stack	*a;
	t_stack	*b;
	char	*join_args;
}	t_stacks;

/* Stack operations */
void		swap(t_stack *stack);
void		push(t_stack *src, t_stack *dest);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);

/* Command operations */
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

/* Sorting functions */
void		sort_3(t_stack *a);
void		sort_4_5(t_stack *a, t_stack *b);
void		radix_sort(t_stack *a, t_stack *b);

/* Helper functions */
int			is_sorted(t_stack *stack);
int			get_min(t_stack *stack);
int			get_max(t_stack *stack);
int			find_position(t_stack *stack, int val);
int			get_target_pos(t_stack *a, int b_val);
void		move_to_top(t_stack *stack, int pos, char stack_name);
void		free_stack(t_stack *stack);
void		free_and_exit(t_stacks *stack, char *msg);
void		create_index(t_stack *stack);
void		check_duplicates(int *numbers, int count);
long		ft_atol(const char *str);
void		exit_error(void);
int			ft_number(int i);

/* Parsing and initialization */
void		parse_args(int argc, char **argv, t_stacks *stack);
void		fill_stack(t_stack *stack, int *tablica, int count);
int			*parse_numbers(t_stacks *stack, int *count);
void		validate_args(int argc, char **argv);

#endif
