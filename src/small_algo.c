/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:31:51 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/09/29 20:49:15 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_dispatch(t_stack *stack)
{
	if (stack->size_a == 2)
		sa(stack);
	if (stack->size_a == 3)
		algo_3(stack);
	if (stack->size_a == 5)
		algo_5(stack);
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
	check_sorted_stack_a(stack);
}

void	algo_5(t_stack	*stack)
{
	pb(stack);
	pb(stack);
	algo_3(stack);
	if (stack->b[0] >)
}
