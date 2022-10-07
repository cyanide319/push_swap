/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:43:27 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/10/07 17:52:27 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	check_sorted(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < stack->size + 1)
	{
		if (stack->input[i] > stack->input[j])
			break ;
		if (stack->input[i] < stack->input[j])
		{
			i++;
			if (i == stack->size)
			{
				write (2, "Error\n", 6);
				clean_quit(stack);
			}
			j++;
		}
	}
	return (true);
}

t_bool	check_duplicate(t_stack	*stack, int i)
{
	int	j;

	j = i - 1;
	while (j >= 0)
	{
		if (stack->input[i] == stack->input[j])
			return (false);
		j--;
	}
	return (true);
}

t_bool	check_min_max(char **array, int j, t_stack *stack)
{
	long	n;
	int		i;
	int		max;

	i = 0;
	max = j;
	while (j <= stack->size + max)
	{
		n = ft_atol(array[j]);
		if (n < INT_MIN || n > INT_MAX)
			return (false);
		j++;
		stack->input[i] = (int)n;
		if (i >= 1 && check_duplicate(stack, i) == false)
			return (false);
		i++;
	}
	return (true);
}

t_bool	check_digit(char **array, int j, t_stack *stack)
{
	int	i;
	int	max;

	max = j;
	while (j <= stack->size + max)
	{
		i = 0;
		if (array[j][i] == '-')
			i++;
		while (array[j][i])
		{
			if (array[j][i] < '0' || array[j][i] > '9')
				return (false);
			i++;
		}
		j++;
	}
	return (true);
}

void	check_error(char **array, int j, t_stack *stack)
{
	if (check_digit(array, j, stack) == false
		|| check_min_max(array, j, stack) == false
		|| check_sorted(stack) == false)
	{
		write (2, "Error\n", 6);
		clean_quit(stack);
	}

}
