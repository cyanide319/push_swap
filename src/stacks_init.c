/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:16:17 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/09/29 15:23:30 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stacks(t_stack *stack)
{
	int	i;
	int	j;
	int	n;
	int	fuck;

	i = 0;
	j = stack->size;
	if (!stack)
		clean_quit(stack);
	stack->b = malloc(sizeof(int) * stack->size + 1);
	if (!stack->b)
		clean_quit(stack);
	while (j >= 0)
	{
		n = stack->input[j];
		stack->a[i] = index_stack(stack, n);
		i++;
		j--;
	}
	fuck = -1;
	while (fuck < stack->size)
	{
		ft_printf("%d\n", stack->a[++fuck]);
	}
}

int	index_stack(t_stack *stack, int n)
{
	int	i;
	int	index;

	index = 1;
	i = 0;
	while (i <= stack->size)
	{
		if (n > stack->input[i])
		{
			index++;
		}
		i++;
	}
	return (index);
}

void	dispatch(int argc, char **argv, t_stack *stack)
{
	if (argc == 1)
	{
		exit (0);
	}
	if (argc == 2)
	{
		stack->size = ft_count(argv[1], ' ') - 1;
		stack->temp = ft_split(argv[1], ' ');
		stack->input = malloc(sizeof(int) * stack->size + 1);
		stack->a = malloc(sizeof(int) * stack->size + 1);
		if (!stack->input || !stack->a)
			clean_quit(stack);
		check_error(stack->temp, 0, stack);
	}
	else
	{
		stack->size = argc - 2;
		stack->input = malloc(sizeof(int) * stack->size + 1);
		stack->a = malloc(sizeof(int) * stack->size + 1);
		if (!stack->input || !stack->a)
			clean_quit(stack);
		check_error(argv, 1, stack);
	}
}
