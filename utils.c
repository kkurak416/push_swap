/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:10:04 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/04/29 12:10:06 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	if (a->size >= 2)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack *b)
{
	if (b->size >= 2)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->size >= 2 && b->size >= 2)
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
	}
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size > 0)
	{
		push(b, a);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
	{
		push(a, b);
		write(1, "pb\n", 3);
	}
}
