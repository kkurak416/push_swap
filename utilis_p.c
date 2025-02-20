/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:27:38 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/02/18 17:27:17 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (is_valid_stack(stack_b))
	{
		temp = stack_b->top;
		stack_b->top = stack_b->top->next;
		temp->next = stack_a->top;
		stack_a->top = temp;
		return (1);
	}
	return (0);
}

int pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if(is_valid_stack(stack_a))
	{
		temp = stack_a->top;
		stack_a->top = stack_a->top->next;
		temp->next = stack_b->top;
		stack_b->top = temp;
		return (1);
	}
	return (0);
}
