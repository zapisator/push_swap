/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_initial_push_to_b.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:06:50 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/03 19:06:52 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void			set_min_and_max_of_three(t_dlist *stack_x, int *mid,
		t_calc *result)
{
	int				fst;
	int				snd;
	int				trd;

	fst = CALC_NBR(stack_x);
	snd = CALC_NBR(stack_x->next);
	trd = CALC_NBR(stack_x->prev);
	*mid = ft_imax(ft_imin(fst, snd), ft_imin(ft_imax(fst, snd), trd));
	result->max = ft_imax(ft_imax(fst, snd), trd);
	result->min = ft_imin(ft_imin(fst, snd), trd);
	return ;
}

void				common_push_except_three(t_calc *result)
{
	int				mid;
	int				i;

	i = result->nbrs_count;
	while (i-- > 3)
		PB(result);
	set_min_and_max_of_three(result->stack_a, &mid, result);
	if (CALC_NBR((result->stack_a)) == result->max)
		RA(result);
	else if (CALC_NBR((result->stack_a)->next) == result->max)
		RRA(result);
	if (CALC_NBR((result->stack_a)) == mid)
		SA(result);
	return ;
}
