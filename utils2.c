/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:14:45 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/04/29 12:17:08 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (a->size >= 2)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack *b)
{
	if (b->size >= 2)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->size >= 2 && b->size >= 2)
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
}
