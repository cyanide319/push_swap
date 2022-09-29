/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:27:35 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/09/29 17:55:16 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_stack *stack)
{
	int	temp;

	if (stack->size_a == 0)
		return ;
	temp = stack->a[stack->size_a - 1];
	stack->a[stack->size_a - 1] = 0;
	stack->b[stack->size_b] = temp;
	stack->size_a--;
	stack->size_b++;
	write (1, "pb\n", 3);
}

void	sa(t_stack *stack)
{
	int	temp;

	if (stack->size_a >= 2)
	{
		temp = stack->a[stack->size_a - 1];
		stack->a[stack->size_a - 1] = stack->a[stack->size_a - 2];
		stack->a[stack->size_a - 2] = temp;
		write (1, "sa\n", 3);
	}
}

void	rra(t_stack *stack)
{
	int	temp;
	int	j;
	int	i;

	temp = stack->a[stack->size_a - 1];
	i = stack->size_a - 1;
	j = i - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[j];
		i--;
		j--;
	}
	stack->a[0] = temp;
	write (1, "rra\n", 3);
}

void	ra(t_stack *stack)
{
	int	temp;
	int	j;
	int	i;

	temp = stack->a[0];
	i = 0;
	j = 1;
	while (j < stack->size_a)
	{
		stack->a[i] = stack->a[j];
		i++;
		j++;
	}
	stack->a[stack->size_a - 1] = temp;
	write (1, "ra\n", 4);
}
