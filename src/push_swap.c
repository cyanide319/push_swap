/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:35:43 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/10/07 17:58:33 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clean_quit(t_stack *stack)
{
	if (stack->input)
		free(stack->input);
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack->temp)
		double_free(&stack->temp);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	ft_bzero(&stack, sizeof(stack));
	dispatch(argc, argv, &stack);
	init_stacks(&stack);
	stack.chunk = 15;
	if (stack.size >= 250)
		stack.chunk = 34;
	algo_dispatch(&stack);
	clean_quit(&stack);
}
