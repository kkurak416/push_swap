/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:07:10 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/02/18 16:25:31 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(t_stack *stack, int value)
{
	t_node *new_node = malloc(sizeof(t_node));
	if(!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	new_node->prev = NULL;
	if(stack->top)
		stack->top->prev = new_node;
	else
		stack->bottom = new_node;
	stack->top = new_node;
	stack->size++;
}
