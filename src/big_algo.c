/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:41:18 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/10/05 20:04:17 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	next_in_b(t_stack *stack)
{
	int	nb;
	int	count;

	nb = 0;
	count = 0;
	while (count < stack->size_b)
	{
		if (stack->b[count] > nb)
			nb = stack->b[count];
		count++;
	}
	return (nb);
}

int	number_is_in_range(t_stack *stack)
{
	int	count;

	count = 0;
	while (count < stack->size_a)
	{
		if (stack->a[count] < (stack->size / 2 + stack->ch)
			&& stack->a[count] > (stack->size / 2 - stack->ch))
			return (1);
		count++;
	}
	return (0);
}

void	b_to_a(t_stack *stack)
{
	int	next;
	int	count;

	while (stack->size_b)
	{
		next = next_in_b(stack);
		if (stack->b[stack->size_b - 1] == next
			|| stack->b[stack->size_b - 1] == next - 1)
		{
			pa(stack);
			if (stack->a[stack->size_a - 1] > stack->a[stack->size_a - 2])
				sa(stack);
		}
		else
		{
			count = best_path(stack, next);
			while (stack->b[stack->size_b - 1] != next)
			{
				if (count > stack->size_b / 2)
					rb(stack);
				else
					rrb(stack);
			}
		}
	}
}

void	a_to_b(t_stack *stack)
{
	int	med;
	int	still_nb_in_chunk;

	med = stack->size_a / 2;
	stack->ch = stack->chunk;
	while (stack->size_a)
	{
		still_nb_in_chunk = number_is_in_range(stack);
		if (still_nb_in_chunk)
		{
			if (stack->a[stack->size_a - 1] >= med - stack->ch
				&& stack->a[stack->size_a - 1] <= med + stack->ch)
			{
				pb(stack);
				if (stack->b[stack->size_b - 1] < med)
					rb(stack);
			}
			else
				ra(stack);
		}
		else
			stack->ch += stack->chunk;
	}
}
