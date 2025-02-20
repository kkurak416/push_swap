/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:29:17 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/02/18 18:08:13 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ra (t_stack *stack_a)
{
	t_node	*temp;
	t_node	*last;

	last = stack_a->top;
	if (is_valid_stack(stack_a))
	{
		temp = stack_a->top;
		stack_a->top = stack_a->top->next;
		temp->next = NULL;
		while (last->next != NULL)
			last = last->next;
		last->next = temp;
		return(1);
	}
	return(0);
}

int rb (t_stack *stack_b)
{

	t_node	*temp;
	t_node	*last;

	last = stack_b->top;
	if (is_valid_stack(stack_b))
	{
		temp = stack_b->top;
		stack_b->top = stack_b->top->next;
		temp->next = NULL;
		while (last->next != NULL)
			last = last->next;
		last->next = temp;
		return (1);
	}
	return (0);
}

int rr (t_stack *stack_a, t_stack *stack_b)
{
	if (is_valid_stack(stack_a) && is_valid_stack(stack_b))
	{
		ra(stack_a);
		rb(stack_b);
		return (1);
	}
	return (0);
}
