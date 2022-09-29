/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:36:52 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/09/28 18:30:03 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "include/printf/ft_printf.h"
# include "include/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack{
	int			*input;
	int			*a;
	int			*b;
	int			size;
	char		**temp;
}t_stack;

typedef enum e_bool{
	true,
	false,
}t_bool;

//utils
long	ft_atol(const char *str);
void	double_free(char	***tabp);

//errors - quits
t_bool	check_sorted(t_stack *stack);
t_bool	check_duplicate(t_stack	*stack, int i);
t_bool	check_min_max(char **array, int j, t_stack *stack);
t_bool	check_digit(char **array, int j, t_stack *stack);
void	check_error(char **argv, int index, t_stack *stack);
void	clean_quit(t_stack *stack);

//stacks
void	init_stacks(t_stack *stack);
void	dispatch(int argc, char **argv, t_stack *stack);
int		index_stack(t_stack *stack, int n);

#endif
