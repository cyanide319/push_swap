/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:41:18 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/10/05 17:35:29 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	big_algo(t_stack *stack)
// {
// 	while (stack->size_b < (stack->size / 3))
// 	{
// 		if (stack->a[stack->size_a - 1] < (stack->size / 3))
// 			pb(stack);
// 		else
// 			ra(stack);
// 	}
// 	while (stack->size_b < (stack ))
// }

void	big_algo(t_stack *stack)
{
	int	x;
	int	i;
	int	y;

	x = 4;
	while (x >= 0)
	{
		y = 9 - x;
		i = stack->size_a;
		while (i--)
		{
			big_algo_2(stack, x, y);
		}
		x--;
	}
}

void	big_algo_2(t_stack *stack, int x, int y)
{
	if (stack->a[stack->size_a - 1] == 100)
		ra(stack);
	else if (stack->a[stack->size_a - 1] % 10 == x
		|| stack->a[stack->size_a - 1] % 10 == y)
	{
		if (stack->a[stack->size_a - 1] % 10 == x)
		{
			pb(stack);
			rb(stack);
		}
		else if (stack->a[stack->size_a - 1] % 10 == y)
			pb(stack);
	}
	else
		ra(stack);
}

void	push_back(t_stack *stack)
{
	int	x;
	int	i;

	x = stack->size / 10;
	while (x >= 0)
	{
		i = stack->size_b;
		while (i--)
		{
			if (stack->b[stack->size_b - 1] / 10 == x)
				pa(stack);
			else
			{
				rb(stack);
			}
		}
		x--;
	}
}

int	best_path(t_stack *stack, int nb)
{
	int	i;
	int	j;

	i = 0;
	j = stack->size_b - 1;
	while (stack->b[i] != nb)
	{
		i++;
	}
	while (stack->b[j] != nb)
	{
		j--;
	}
	if (stack->size_b - j < i)
		return (j);
	else
		return (i);
}
