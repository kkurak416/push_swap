/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <kkurowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:29:38 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/05/07 17:27:59 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	free_and_exit(t_stacks *stack, char *msg)
{
	if (msg)
	{
		ft_putendl_fd(msg, 2);
		exit(2);
	}
	if (stack)
	{
		if (stack->a)
		{
			free_stack(stack->a);
			free(stack->a);
		}
		if (stack->b)
		{
			free_stack(stack->b);
			free(stack->b);
		}
		if (stack->join_args)
			free(stack->join_args);
		free(stack);
	}
	exit(0);
}

void	check_duplicates(int *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				exit_error();
			j++;
		}
		i++;
	}
}

long	ft_atol(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

int	ft_number(int i)
{
	if ((i >= '0' && i <= '9') || i == ' ')
		return (1);
	else
		return (0);
}
