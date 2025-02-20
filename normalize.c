/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:32:18 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/02/19 19:40:04 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_of_stack(t_stack *stack)
{
	t_node *temp;
	int	i;

	i = 0;
	temp = stack->top;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	partition (int *array, int low, int high)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if(array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	return(i + 1);
}

void quick_sort(int *array, int low, int high)
{
	int	pi;
	t_quick_node	*stack;
	t_quick_node	*temp;

	stack = NULL;
	if (low < high)
	{
		pi = partition(array, low, high);
		temp = malloc(sizeof(t_quick_node));
		if (!temp)
			return ;
		temp->low = low;
		temp->high = high;
		temp->next = stack;
		stack = temp;
		quick_sort(array, low, pi - 1);
		quick_sort(array, pi + 1, high);
		stack = stack->next;
		free (temp);
	}
}

void	fill_values(int *values, t_stack *stack)
{
	t_node	*current;
	int		idx;

	current = stack->top;
	idx = 0;
	while (current)
	{
		values[idx++] = current->value;
		current = current->next;
	}
}

void normalize_stack(t_stack *stack)
{
	t_node	*current;
	int	*values;
	int	size;
	int	idx;

	size = size_of_stack(stack);
	values = malloc(sizeof(int) *size);
	if(!values)
		return ;
	fill_values(values, stack);
	quick_sort(values, 0, size - 1);
	current = stack->top;
	while (current)
	{
		idx = 0;
		while(values[idx] != current->value)
			idx++;
		current->value = idx;
		current = current->next;
	}
	free(values);
}
