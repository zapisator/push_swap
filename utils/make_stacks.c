/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:38:42 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/02 20:42:44 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int					make_stacks(int **nbrs, int inst_size,
		t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist			*node;
	int				*nbr_ar;

	nbr_ar = *nbrs;
	*stack_a = NULL;
	*stack_b = NULL;
	node = NULL;
	while (inst_size--)
	{
		if (!(node = ft_dlstnew((void *)nbr_ar++, sizeof(*nbr_ar))))
		{
			ft_dlstdel(stack_a, ft_dlstcontentdel);
			ft_memdel((void *)nbrs);
			return (FAILURE);
		}
		ft_dlstaddtip(stack_a, node);
	}
	return (SUCCESS);
}
