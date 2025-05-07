/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <kkurowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:35:28 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/05/07 17:27:29 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_stuff(int argc, char **argv, t_stacks *stack)
{
	int	*tablica;
	int	count;

	stack->a->top = NULL;
	stack->a->size = 0;
	stack->b->top = NULL;
	stack->b->size = 0;
	stack->join_args = NULL;
	parse_args(argc, argv, stack);
	tablica = parse_numbers(stack, &count);
	check_duplicates(tablica, count);
	fill_stack(stack->a, tablica, count);
	free(tablica);
	create_index(stack->a);
}

void	sorting(t_stacks *stack)
{
	if (!is_sorted(stack->a))
	{
		if (stack->a->size == 2)
			sa(stack->a);
		else if (stack->a->size == 3)
			sort_3(stack->a);
		else if (stack->a->size <= 5)
			sort_4_5(stack->a, stack->b);
		else
			radix_sort(stack->a, stack->b);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stack;

	if (argc == 1)
		return (0);
	validate_args(argc, argv);
	stack = malloc(sizeof(t_stacks));
	if (!stack)
		exit(1);
	stack->a = malloc(sizeof(t_stack));
	stack->b = malloc(sizeof(t_stack));
	if (!stack->a || !stack->b)
		free_and_exit(stack, "Error");
	do_stuff(argc, argv, stack);
	sorting(stack);
	free_and_exit(stack, NULL);
	return (0);
}
