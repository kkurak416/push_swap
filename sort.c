/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:37:47 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/02/20 19:32:07 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max(int *values, int size, int idx, int max)
{
    if (idx == size)
        return max;
    if (values[idx] > max)
        max = values[idx];
    return find_max(values, size, idx + 1, max);
}

int get_max_bits(t_stack *stack)
{
    t_node *current = stack->top;
    int *values;
    int size = size_of_stack(stack);
    int max;
    int bits = 0;

    values = malloc(sizeof(int) * size);
    if (!values)
        return (0);

    int idx = 0;
    while (current)
    {
        values[idx++] = current->value;
        current = current->next;
    }

    max = find_max(values, size, 0, values[0]);

    while (max >> bits)
        bits++;

    free(values);
    return bits;
}

void radix_sort(t_stack *stack_a, t_stack *stack_b, int bit)
{
    int size = size_of_stack(stack_a);

    if (bit >= get_max_bits(stack_a)) // Zatrzymujemy się, jeśli osiągniemy koniec bitów
        return;

    // Przetwarzamy każdy element w zależności od bitu
    t_node *current = stack_a->top;
    while (current)
    {
        if ((current->value >> bit) & 1)
            pa(stack_a, stack_b);  // Przenieś na stack_b, jeśli bit jest ustawiony na 1
        else
            rra(stack_a);  // Wróć na dół stack_a, jeśli bit jest ustawiony na 0
        current = current->next;
    }

    // Zwracamy wszystkie elementy z stack_b z powrotem do stack_a
    move_back_to_stack_a(stack_a, stack_b);

    // Rekurencyjne przejście do następnego bitu
    radix_sort(stack_a, stack_b, bit + 1);
}

// Funkcja pomocnicza do przenoszenia elementów z stack_b z powrotem do stack_a
void move_back_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_b->top != NULL)
        pb(stack_a, stack_b);
}

int size_of_stack(t_stack *stack)
{
    t_node *temp;
    int i;

    i = 0;
    temp = stack->top;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return (i);
}
