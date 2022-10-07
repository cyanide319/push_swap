/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:31:51 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/10/07 13:54:42 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_dispatch(t_stack *stack)
{
	if (stack->size_a == 2)
		sa(stack);
	if (stack->size_a == 3)
		algo_3(stack);
	if (stack->size_a == 5 || stack->size_a == 4)
		algo_5(stack);
	if (stack->size_a > 5)
	{
		a_to_b(stack);
		b_to_a(stack);
	}
}

void	algo_3(t_stack *stack)
{
	if ((stack->a[0] < stack->a[1]) && (stack->a[1] > stack->a[2]))
	{
		if (stack->a[0] > stack->a[2])
		{
			rra(stack);
			sa(stack);
		}
		else
			rra(stack);
	}
	if ((stack->a[0] > stack->a[1]) && (stack->a[1] < stack->a[2]))
	{
		if (stack->a[0] < stack->a[2])
			ra(stack);
		else
			sa(stack);
	}
	if ((stack->a[0] < stack->a[1]) && (stack->a[1] < stack->a[2]))
	{
		ra(stack);
		sa(stack);
	}
}

void	algo_5(t_stack	*stack)
{
	while (stack->size_a > 3)
	{
		if (stack->a[stack->size_a - 1] > 3)
			pb(stack);
		else if (stack->a[0] > 3)
			rra(stack);
		else if (stack->a[stack->size_a - 2] > 3)
			sa(stack);
		else if (stack->a[1] > 3 || stack->a[stack->size_a - 3] > 3)
			ra(stack);
	}
	algo_3(stack);
	if (stack->b[0] < stack->b[1])
		rb(stack);
	pa(stack);
	ra(stack);
	pa(stack);
	if (stack->size_a == 5)
		ra(stack);
}
