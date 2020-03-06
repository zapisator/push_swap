/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:55:47 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/26 20:00:30 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

/*
**								swap
*/

void				swap(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist			*fst_out;
	t_dlist			*last_out;

	fst_out = NULL;
	last_out = NULL;
	if (stack_a && *stack_a)
	{
		fst_out = ft_dlstpop(stack_a);
		last_out = ft_dlstpop(stack_a);
		ft_dlstpush(stack_a, fst_out);
		ft_dlstpush(stack_a, last_out);
	}
	if (stack_b && *stack_b)
	{
		fst_out = ft_dlstpop(stack_b);
		last_out = ft_dlstpop(stack_b);
		ft_dlstpush(stack_b, fst_out);
		ft_dlstpush(stack_b, last_out);
	}
	return ;
}

/*
**								push
*/

void				push(t_dlist **stack_dst, t_dlist **stack_src)
{
	ft_dlstpush(stack_dst, ft_dlstpop(stack_src));
	return ;
}

/*
**								rotate
*/

void				rotate(t_dlist **stack_a, t_dlist **stack_b)
{
	if (stack_a && *stack_a)
		ft_dlstpush_back(stack_a, ft_dlstpop(stack_a));
	if (stack_b && *stack_b)
		ft_dlstpush_back(stack_b, ft_dlstpop(stack_b));
	return ;
}

/*
**								reverse rotate
*/

void				r_rotate(t_dlist **stack_a, t_dlist **stack_b)
{
	if (stack_a && *stack_a)
		ft_dlstpush(stack_a, ft_dlstpop_rear(stack_a));
	if (stack_b && *stack_b)
		ft_dlstpush(stack_b, ft_dlstpop_rear(stack_b));
	return ;
}

/*
**								erroneous
*/

void				op_error(t_dlist **stack_a, t_dlist **stack_b)
{
	(void)stack_a;
	(void)stack_b;
	ft_putendl_fd("Error, when define op_func()", STDERR);
	return ;
}
