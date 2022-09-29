/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_multi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:56:10 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/09/29 18:57:43 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
