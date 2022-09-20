/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:35:43 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/09/20 17:54:39 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	dispatch(int argc, char **argv, t_stack *stack)
{
	char	**temp;
	int		i;
	int		j;

	if (argc == 1)
	{
		write (1, "Error\n", 6);
		exit (0);
	}
	if (argc == 2)
	{
		i = ft_count(argv[1], ' ');
		temp = ft_split(argv[1], ' ');
		j = 0;
	}
	else
	{
		temp = argv;
		i = argc;
		j = 1;
	}
	check_error(i, temp, j, stack);
	if (argc == 2)
		double_free(temp);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		i;

	dispatch(argc, argv, &stack);
	i = 0;
	while (i < stack.stack_size)
	{
		ft_printf("%d\n", stack.stack_a[i]);
		i++;
	}
	free(stack.stack_a);
}
