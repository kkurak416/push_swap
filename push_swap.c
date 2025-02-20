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
/*
int main(int argc, char **argv)
{
	t_stack	*stack;
	int	i;
	int	j;

	if (argc < 2)
		return (0);
	stack = malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		push_swap(stack, ft_atoi(argv[i]));
		i++;
	}
}*/

int main(int argc, char **argv)
{
    t_stack *stack;
    int i;

    if (argc < 2)
        return (0);

    stack = malloc(sizeof(t_stack));
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;

    i = 1;
    while (i < argc)
    {
        if (ft_isdigit(argv[i][0])) // poprawka, bo argv[i] to string
        {
            push_swap(stack, ft_atoi(argv[i]));
        }
        else
        {
            printf("Error: invalid input\n");
            return (0);
        }
        i++;
    }

    // 🛠 Sprawdzenie, czy liczby są poprawnie dodane do stosu
    printf("Stack elements:\n");
    t_node *current = stack->top;
    while (current)
    {
        printf("%d\n", current->value);
        current = current->next;
    }

    return (0);
}

