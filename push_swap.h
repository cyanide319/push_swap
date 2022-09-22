/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:36:52 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/09/21 21:52:20 by tbeaudoi         ###   ########.fr       */
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
	int			*stack_a;
	int			*stack_b;
	int			stack_size;
	char		**temp;
}t_stack;

typedef enum e_bool{
	true,
	false,
}t_bool;

long	ft_atol(const char *str);
void	check_error(char **argv, int index, t_stack *stack);
void	double_free(char	***tabp);
void	clean_quit(t_stack *stack);

#endif
