/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:01:28 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 12:08:56 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void				write_ops(char ops_i[BEST_SIZE], int ops_size)
{
	char			ops_str[BEST_SIZE * 4 + 1];
	int				size;
	int				i;
	static char		*ops[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
					"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};

	ft_bzero(ops_str, BEST_SIZE * 4 + 1);
	size = 0;
	i = ops_size;
	while (i--)
	{
		ft_memcpy(ops_str + size, *(ops + *ops_i), ft_strlen(*(ops + *ops_i)));
		size += ft_strlen(*(ops + *ops_i));
		++ops_i;
	}
	write(STDOUT, ops_str, size);
	return ;
}

static int			check_if_issorted(int *nbrs, int nbrs_count)
{
	int				i;

	i = 0;
	while (--nbrs_count)
	{
		if (*(nbrs + i) > *(nbrs + i + 1))
			return (!TRUE);
		++i;
	}
	return (!!TRUE);
}

static void			make_calculations(t_calc *result)
{
	result->ops_size = 0;
	if (result->nbrs_count > 2)
	{
		result->size_a = result->nbrs_count;
		common_push_except_three(result);
		while (result->stack_b)
		{
			calculate(result);
			make_best_estimation(result);
		}
		while (CALC_NBR(result->stack_a) != result->min)
			RA(result);
	}
	else if (result->nbrs_count == 2 &&
			CALC_NBR(result->stack_a) > CALC_NBR(result->stack_a->next))
		SA(result);
	return ;
}

static void			push_swap_free(int *nbrs, t_calc *result)
{
	free(nbrs);
	ft_dlstdel(&result->stack_a, ft_dlstcontentdel);
	ft_dlstdel(&result->stack_b, ft_dlstcontentdel);
	return ;
}

int					main(int argc, char **argv)
{
	int				*nbrs;
	t_calc			result;

	if (argc < 2)
		return (usage_ps());
	ft_bzero((void *)&result, sizeof(result));
	if (fill_nbrs(argc, argv, &nbrs, &result.nbrs_count) != FAILURE &&
			make_stacks(&nbrs, result.nbrs_count, &result.stack_a,
				&result.stack_b) != FAILURE)
	{
		if (check_if_issorted(nbrs, result.nbrs_count))
			ft_putendl("");
		else
		{
			make_calculations(&result);
			write_ops(result.ops_i, result.ops_size);
		}
	}
	push_swap_free(nbrs, &result);
	return (SUCCESS);
}
