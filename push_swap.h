/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:32:12 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/02/18 17:32:46 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
// struktura listy
typedef struct s_node
{
    int             value;
    struct s_node   *next;
    struct s_node   *prev;
} t_node;
//struktura do quick_sort
typedef struct s_node {
    int low;
    int high;
    struct s_node *next;
} t_node;
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

#endif
