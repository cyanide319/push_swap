/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:36:52 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/09/29 20:43:08 by tbeaudoi         ###   ########.fr       */
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
	int			size_a;
	int			size_b;
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
void	check_sorted_stack_a(t_stack *stack);

//stacks
void	init_stacks(t_stack *stack);
void	dispatch(int argc, char **argv, t_stack *stack);
int		index_stack(t_stack *stack, int n);

//moves stack a
void	pb(t_stack *stack);
void	sa(t_stack *stack);
void	ra(t_stack *stack);
void	rra(t_stack *stack);

//moves stack b
void	pa(t_stack *stack);
void	sb(t_stack *stack);
void	rb(t_stack *stack);
void	rrb(t_stack *stack);

//moves multi
void	ss(t_stack *stack);
void	rr(t_stack *stack);
void	rrr(t_stack *stack);

//algorithm
void	algo_dispatch(t_stack *stack);
void	algo_3(t_stack *stack);

#endif
