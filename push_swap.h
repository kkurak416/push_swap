/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:32:12 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/02/20 12:06:11 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
// struktura listy
typedef struct s_node
{
    int             value;
    struct s_node   *next;
    struct s_node   *prev;
} t_node;
//struktura do quick_sort
typedef struct s_quick_node {
    int low;
    int high;
    struct s_quick_node *next;
} t_quick_node;
//struktura stosu
typedef struct s_stack
{
	t_node  *top;
	t_node  *bottom;
	int     size;
} t_stack;

int	is_valid_stack(t_stack *stack);
int	sa(t_stack *stack_a);
int	sb(t_stack *stack_b);
int	ss(t_stack *stack_a, t_stack *stack_b);
int	pa(t_stack *stack_a, t_stack *stack_b);
int	pb(t_stack *stack_a, t_stack *stack_b);
int	rra(t_stack *stack_a);
int	rrb(t_stack *stack_b);
int	rrr(t_stack *stack_a, t_stack *stack_b);
int	size_of_stack(t_stack *stack);
int	partition (int *array, int low, int high);
void	quick_sort(int *array, int low, int high);
void	fill_values(int *values, t_stack *stack);
void	normalize_stack(t_stack *stack);

#endif
