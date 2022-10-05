/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:31:51 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/10/05 17:28:55 by tbeaudoi         ###   ########.fr       */
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
	if (stack->size_a >= 100)
	{
		big_algo(stack);
		push_back(stack);
		ft_printf("ops: %d\n", stack->nb_ops);
		check_sorted_stack_a(stack);
		clean_quit(stack);
	}
	if (stack->size_a == 500)
	{
		big_algo(stack);
		push_back(stack);
		// push_back_again(stack);
		// while (stack->size_b > 0)
		// 	pa(stack);
		ft_printf("ops: %d\n", stack->nb_ops);
		check_sorted_stack_a(stack);
		clean_quit(stack);
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
	ft_printf("ops: %d\n", stack->nb_ops);
	check_sorted_stack_a(stack);
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
	ra(stack);
	ft_printf("ops: %d\n", stack->nb_ops);
	check_sorted_stack_a(stack);
	clean_quit(stack);
}
