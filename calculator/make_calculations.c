/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:34:00 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/03 19:42:14 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void				refresh_extremums(t_calc *result)
{
	if (CALC_NBR(result->stack_b) > result->max)
		result->max = CALC_NBR(result->stack_b);
	else if (CALC_NBR(result->stack_b) < result->min)
		result->min = CALC_NBR(result->stack_b);
	return ;
}

static void			make_rx_rr(t_calc *result)
{
	int				rx_nbr;
	int				rr_nbr;
	int				i;

	rr_nbr = ft_imin(OP_BEST(ra), OP_BEST(rb));
	rx_nbr = ft_imax(OP_BEST(ra), OP_BEST(rb)) - rr_nbr;
	i = rr_nbr;
	while (i--)
		RR(result);
	if (OP_BEST(ra) == rr_nbr + rx_nbr)
		while (rx_nbr--)
			RA(result);
	else
		while (rx_nbr--)
			RB(result);
	refresh_extremums(result);
	PA(result);
	return ;
}

static void			make_rrx_rrr(t_calc *result)
{
	int				rrx_nbr;
	int				rrr_nbr;
	int				i;

	rrr_nbr = ft_imin(OP_BEST(rra), OP_BEST(rrb));
	rrx_nbr = ft_imax(OP_BEST(rra), OP_BEST(rrb)) - rrr_nbr;
	i = rrr_nbr;
	while (i--)
		RRR(result);
	if (OP_BEST(rra) == rrr_nbr + rrx_nbr)
		while (rrx_nbr--)
			RRA(result);
	else
		while (rrx_nbr--)
			RRB(result);
	refresh_extremums(result);
	PA(result);
	return ;
}

static void			make_rx_rry(t_calc *result)
{
	if (OP_BEST(ra) + OP_BEST(rrb) < OP_BEST(rb) + OP_BEST(rra))
	{
		while (OP_BEST(ra)--)
			RA(result);
		while (OP_BEST(rrb)--)
			RRB(result);
	}
	else
	{
		while (OP_BEST(rb)--)
			RB(result);
		while (OP_BEST(rra)--)
			RRA(result);
	}
	refresh_extremums(result);
	PA(result);
	return ;
}

void				make_best_estimation(t_calc *result)
{
	if (OP_BEST(summary) == ft_imax(OP_BEST(ra), OP_BEST(rb)))
		make_rx_rr(result);
	else if (OP_BEST(summary) == ft_imax(OP_BEST(rra), OP_BEST(rrb)))
		make_rrx_rrr(result);
	else if (OP_BEST(summary) == OP_BEST(ra) + OP_BEST(rrb) ||
			OP_BEST(summary) == OP_BEST(rb) + OP_BEST(rra))
		make_rx_rry(result);
	else
		ft_putendl(F_RD_B"Estimation ERROR!"CL);
	return ;
}
