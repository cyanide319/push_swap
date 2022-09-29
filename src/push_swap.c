/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:35:43 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/09/29 18:20:11 by tbeaudoi         ###   ########.fr       */
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
	int		i;

	dispatch(argc, argv, &stack);
	init_stacks(&stack);
	i = 0;
	while (i <= stack.size)
	{
		ft_printf("%d\n", stack.a[i]);
		i++;
	}
	pa(&stack);
	clean_quit(&stack);
}
