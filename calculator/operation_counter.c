/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_counter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:10:44 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/03 19:13:42 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void			refresh_buffer(t_calc *result)
{
	write_ops(result->ops_i, result->ops_size);
	result->ops_size = 0;
	return ;
}

void				ops_counter(t_calc *result, int ops_i, t_dlist **stack_a,
		t_dlist **stack_b)
{
	(*op_dispatcher(ops_i))(stack_a, stack_b);
	result->ops_i[(result->ops_size)++] = ops_i;
	if (ops_i == 3)
	{
		++result->size_a;
		--result->size_b;
	}
	if (ops_i == 4)
	{
		--result->size_a;
		++result->size_b;
	}
	if (result->ops_size == BEST_SIZE)
		refresh_buffer(result);
	return ;
}
