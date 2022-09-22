/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:35:43 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/09/21 21:52:02 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	dispatch(int argc, char **argv, t_stack *stack)
{
	int	j;

	if (argc == 1)
	{
		exit (0);
	}
	if (argc == 2)
	{
		stack->stack_size = ft_count(argv[1], ' ') - 1;
		stack->temp = ft_split(argv[1], ' ');
		j = 0;
		stack->stack_a = malloc(sizeof(int) * stack->stack_size);
		if (!stack->stack_a)
			clean_quit(stack);
		check_error(stack->temp, j, stack);
	}
	else
	{
		stack->stack_size = argc - 2;
		j = 1;
		stack->stack_a = malloc(sizeof(int) * stack->stack_size - 1);
		if (!stack->stack_a)
			clean_quit(stack);
		check_error(argv, j, stack);
	}
}

void	clean_quit(t_stack *stack)
{
	if (stack->stack_a)
		free(stack->stack_a);
	if (stack->temp)
		double_free(&stack->temp);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		i;

	dispatch(argc, argv, &stack);
	i = 0;
	while (i <= stack.stack_size)
	{
		ft_printf("%d\n", stack.stack_a[i]);
		i++;
	}
	clean_quit(&stack);
}
