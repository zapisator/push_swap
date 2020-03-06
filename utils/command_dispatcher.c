/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_dispatcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:48:46 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/03 19:50:01 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_ops				op_dispatcher(int op_i_biased)
{
	static t_ops	ops[5] = {swap, push, rotate, r_rotate, op_error};
	int				op_i;

	if (0 <= op_i_biased && op_i_biased <= 2)
		op_i = 0;
	else if (3 == op_i_biased || op_i_biased == 4)
		op_i = 1;
	else if (5 <= op_i_biased && op_i_biased <= 7)
		op_i = 2;
	else if (8 <= op_i_biased && op_i_biased <= 10)
		op_i = 3;
	else
		op_i = 4;
	return (ops[op_i]);
}

int					get_instruction_index(char **instructions)
{
	static char		ops[][11 + 1] = {"sa", "sb", "ss", "pa", "pb", "ra",\
					"rb", "rr", "rra", "rrb", "rrr"};
	int				ops_i;

	ops_i = 0;
	while (ops_i < 11)
	{
		if (!ft_strcmp(ops[ops_i], *instructions))
			break ;
		++ops_i;
	}
	return (ops_i);
}
