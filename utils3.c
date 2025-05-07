/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:17:46 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/04/29 12:19:16 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	if (a->size >= 2)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack *b)
{
	if (b->size >= 2)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->size >= 2 && b->size >= 2)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		write(1, "rrr\n", 4);
	}
}
