/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:39:20 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 17:36:43 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void			write_nbr(int isprinted_a, int isprinted_b,
		t_dlist *nbr_a, t_dlist *nbr_b)
{
	char			ar[20];
	char			*end;

	if (isprinted_a || isprinted_b)
	{
		end = ar;
		if (isprinted_a)
		{
			end = ft_imaxtostr(ar, *(int *)nbr_a->content, 10, TRUE);
			ft_putstr(ar);
		}
		ft_putnstr("                    ", 20 - (end - ar));
		if (isprinted_b)
		{
			(void)ft_imaxtostr(ar, *(int *)nbr_b->content, 10, TRUE);
			ft_putstr(ar);
		}
		ft_putendl("");
	}
	return ;
}

static int			write_op_result(int isprinted_a, int isprinted_b,
		t_dlist *nbr_a, t_dlist *nbr_b)
{
	int				isbreak;

	isbreak = !TRUE;
	write_nbr(isprinted_a, isprinted_b, nbr_a, nbr_b);
	if (!nbr_a && !nbr_b)
	{
		ft_putendl("__________");
		isbreak = TRUE;
	}
	return (isbreak);
}

void				visualize(t_check *ch)
{
	t_dlist			*nbr_a;
	t_dlist			*nbr_b;
	int				isprinted_a;
	int				isprinted_b;

	nbr_a = ch->stack_a;
	nbr_b = ch->stack_b;
	system("sleep "SLEEP_TIME);
	ft_putstr("\e[2J");
	ft_putendl("\n==========");
	while (TRUE)
	{
		isprinted_a = nbr_a ? 1 : 0;
		isprinted_b = nbr_b ? 1 : 0;
		if (write_op_result(isprinted_a, isprinted_b, nbr_a, nbr_b))
			break ;
		if (nbr_a)
			nbr_a = nbr_a->next == ch->stack_a ? NULL : nbr_a->next;
		if (nbr_b)
			nbr_b = nbr_b->next == ch->stack_b ? NULL : nbr_b->next;
	}
	return ;
}
