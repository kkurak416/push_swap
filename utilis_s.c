/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:59:18 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/02/18 16:24:00 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid_stack(t_stack *stack)
{
	return (stack && stack->top && stack->top->next);
}

int sa(t_stack *stack_a)
{
	if (is_valid_stack(stack_a))
		{
		t_node *first = stack_a->top;
		t_node *second = stack_a->top->next;
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		second->prev = NULL;
		second->next = first;
		first->prev = second;
		stack_a->top = second;
		return (1);
		}
	else
		return (0);
}

int sb(t_stack *stack_b)
{
	if (is_valid_stack(stack_b))
	{
	t_node *first = stack_b->top;
	t_node *second = stack_b->top->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack_b->top = second;
	return (1);
	}
	else
		return (0);
}

int ss(t_stack *stack_a, t_stack *stack_b)
{
	if (is_valid_stack(stack_a) && is_valid_stack(stack_b))
	{
		sa(stack_a);
		sb(stack_b);
		return (1);
	}
	return (0);
}
