/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:01:28 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/03 19:41:25 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int			content_intcmp_more(const void *stack_a,
		const void *stack_b)
{
	return (!(
		CALC_NBR((t_dlist *)stack_a) > CALC_NBR((t_dlist *)stack_b) &&
		CALC_NBR(((t_dlist *)stack_a)->prev) < CALC_NBR((t_dlist *)stack_b)));
}

static int			cmp_dlst_nbr(const void *stack_a, const void *nbr)
{
	return (!(CALC_NBR((t_dlist *)stack_a) == *(int *)nbr));
}

static void			count_rx_rrx(t_dlist *stack_b, t_calc *result)
{
	if (CALC_NBR(stack_b) < result->min || result->max < CALC_NBR(stack_b))
		result->curr.ra = ft_dlstfind_i((void *)result->stack_a,
				(void *)&result->min, cmp_dlst_nbr);
	else
		result->curr.ra = ft_dlstfind_i(result->stack_a, stack_b,
					content_intcmp_more);
	result->curr.rra = result->size_a - result->curr.ra;
	if ((result->curr.rb = ft_dlstfind_i(result->stack_b, stack_b,
					ft_dlstcmp)) == FAILURE)
		result->curr.rb = 0;
	if ((result->curr.rrb = ft_dlstfind_ir(result->stack_b, stack_b,
					ft_dlstcmp)) != FAILURE)
		++result->curr.rrb;
	else
		result->curr.rrb = 0;
	return ;
}

static void			get_summary(t_calc *result)
{
	result->curr.summary =
				ft_imin(
					ft_imin(
						OP_NBR(ra) + OP_NBR(rrb),
						OP_NBR(rra) + OP_NBR(rb)),
					ft_imin(
						ft_imax(OP_NBR(ra), OP_NBR(rb)),
						ft_imax(OP_NBR(rra), OP_NBR(rrb))));
	return ;
}

void				calculate(t_calc *result)
{
	t_dlist			*st_curr;

	st_curr = result->stack_b;
	while (TRUE)
	{
		count_rx_rrx(st_curr, result);
		get_summary(result);
		if (!result->isset_best)
		{
			result->isset_best = !!TRUE;
			result->best = result->curr;
		}
		else if (result->curr.summary < result->best.summary)
			result->best = result->curr;
		if (st_curr->next == result->stack_b)
			break ;
		st_curr = st_curr->next;
	}
	result->isset_best = !TRUE;
	return ;
}
