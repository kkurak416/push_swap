/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:23:52 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/04/29 12:23:55 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	push(t_stack *src, t_stack *dest)
{
	t_node	*tmp;

	if (!src->top)
		return ;
	tmp = src->top;
	src->top = src->top->next;
	tmp->next = dest->top;
	dest->top = tmp;
	dest->size++;
	src->size--;
}

void	rotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*current;

	if (!stack->top || !stack->top->next)
		return ;
	temp = stack->top;
	stack->top = stack->top->next;
	temp->next = NULL;
	current = stack->top;
	while (current->next)
		current = current->next;
	current->next = temp;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*current;

	if (!stack->top || !stack->top->next)
		return ;
	temp = NULL;
	current = stack->top;
	while (current->next)
	{
		temp = current;
		current = current->next;
	}
	temp->next = NULL;
	current->next = stack->top;
	stack->top = current;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->size = 0;
}
