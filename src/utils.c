/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:16:38 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/10/03 15:16:26 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(const char *str)
{
	long	nb;
	long	minus;

	nb = 0;
	minus = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '+')
			str++;
		else if (*str == '-')
		{
			minus *= -1;
			str++;
		}
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - 48;
		str++;
	}
	return (nb * minus);
}

void	double_free(char	***tabp)
{
	int		i;
	char	**tab;

	i = 0;
	tab = *tabp;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free (tab);
	*tabp = NULL;
}

void	check_sorted_stack_a(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < stack->size_a)
	{
		if (stack->a[i] < stack->a[j])
		{
			write (1, "Not sorted\n", 11);
			break ;
		}
		if (stack->a[i] > stack->a[j])
		{
			i++;
			if (i == stack->size_a - 1)
			{
				write (1, "Sorted\n", 7);
				break ;
			}
			j++;
		}
	}
}
