/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:11:47 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/02/18 18:57:16 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rra(t_stack *stack_a)
{
	t_node	*last;

	if (is_stack_valid(stack_a))
	{
		last = stack_a->top;
		while (last->next != NULL)
			last = last->next;
		last->prev->next = NULL;
		last->next = stack_a->top;
		stack_a->top->prev = last;
		stack_a->top = last;
		return (1);
	}
	return (0);
}

int rrb(t_stack *stack_b)
{
	t_node	*last;

	if(is_stack_valid(stack_b))
	{
		last = stack_b->top;
		while (last->next != NULL)
			last = last->next;
		last->prev->next = NULL;
		last->next = stack_b->top;
		stack_b->top->prev = last;
		stack_b->top = last;
		return (1);
	}
	return (0);
}

int rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (is_stack_valid(stack_a) && is_stack_valid(stack_b))
	{
		rra(stack_a);
		rrb(stack_b);
		return (1);
	}
	return (0);
}
