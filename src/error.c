/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:43:27 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/09/20 19:33:42 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	check_duplicate(t_stack	*stack, int j)
{
	int	i;

	while (stack->stack_a[j - 1])
	{
		i = j - 1;
		while (stack->stack_a[i - 1])
		{
			if (stack->stack_a[i] == stack->stack_a[j])
				return (false);
			i--;
		}
		j--;
	}
	return (true);
}

t_bool	check_min_max(int args, char **array, int j, t_stack *stack)
{
	long	n;
	int		i;

	i = j;
	stack->stack_a = malloc(sizeof(int) * args);
	if (!stack->stack_a)
		exit(0);
	while (j < args)
	{
		n = ft_atol(array[j]);
		if (n < INT_MIN || n > INT_MAX)
			return (false);
		j++;
		stack->stack_a[i] = (int)n;
		i++;
		if (check_duplicate(stack, j) == false)
			return (false);
	}
	return (true);
}

t_bool	check_alpha(int args, char **array, int j)
{
	int	i;

	i = 0;
	while (j < args)
	{
		while (array[j][i])
		{
			if (array[j][i] == '-')
				i++;
			if (array[j][i] < 48 || array[j][i] > 57)
				return (false);
			i++;
		}
		j++;
	}
	return (true);
}

void	check_error(int args, char **array, int j, t_stack *stack)
{
	if (check_alpha(args, array, j) == false
		|| check_min_max(args, array, j, stack) == false)
	{
		write (1, "Error\n", 6);
		free(stack->stack_a);
		exit (0);
	}
}
