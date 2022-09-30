/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:27:35 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/09/29 20:12:20 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *stack)
{
	int	temp;

	if (stack->size_b == 0)
		return ;
	temp = stack->b[stack->size_b - 1];
	stack->b[stack->size_b - 1] = 0;
	stack->a[stack->size_a] = temp;
	stack->size_b--;
	stack->size_a++;
	write (1, "pa\n", 3);
}

void	sb(t_stack *stack)
{
	int	temp;

	if (stack->size_b >= 2)
	{
		temp = stack->a[stack->size_b - 1];
		stack->b[stack->size_b - 1] = stack->a[stack->size_b - 2];
		stack->b[stack->size_b - 2] = temp;
		write (1, "sb\n", 3);
	}
}

void	rb(t_stack *stack)
{
	int	temp;
	int	j;
	int	i;

	temp = stack->b[stack->size_b - 1];
	i = stack->size_b - 1;
	j = i - 1;
	while (i > 0)
	{
		stack->b[i] = stack->b[j];
		i--;
		j--;
	}
	stack->b[0] = temp;
	write (1, "rb\n", 3);
}

void	rrb(t_stack *stack)
{
	int	temp;
	int	j;
	int	i;

	temp = stack->b[0];
	i = 0;
	j = 1;
	while (j < stack->size_b)
	{
		stack->b[i] = stack->b[j];
		i++;
		j++;
	}
	stack->b[stack->size_b - 1] = temp;
	write (1, "rrb\n", 4);
}
