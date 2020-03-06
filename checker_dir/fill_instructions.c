/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:29:22 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/05 20:40:57 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int					get_instructions(char ***instructions, int *inst_size)
{
	int				gnl_ret;
	char			**line;
	int				inst_border;

	if ((inst_border = BEST_SIZE) <= 0)
		return (FAILURE);
	if (!(*instructions = (char **)ft_memalloc((inst_border + 1) *
					sizeof(**instructions))))
		return (FAILURE);
	line = *instructions;
	ft_bzero((void *)line, inst_border + 1);
	while (((*inst_size)++ < inst_border) &&
			(gnl_ret = ft_get_next_line(STDIN, line++)) &&
			gnl_ret != FAILURE)
	{
		if (*inst_size == inst_border && gnl_ret > 0)
		{
			if (!(*instructions = (char **)ft_realloc(*instructions, *inst_size,
							(inst_border *= 2))))
				return (FAILURE);
			line = *instructions;
		}
	}
	return (SUCCESS);
}

int					check_instructions(char **instructions)
{
	static char		ops[][11 + 1] = {"sa", "sb", "ss", "pa", "pb", "ra",\
					"rb", "rr", "rra", "rrb", "rrr"};
	int				ops_i;
	int				cmp_i;

	cmp_i = 0;
	while (*instructions)
	{
		ops_i = 0;
		while (ops_i < 11)
		{
			if (!(cmp_i = ft_strcmp(ops[ops_i], *instructions)))
				break ;
			else if (ops_i == 10 && cmp_i)
			{
				ft_putendl_fd("Error", STDERR);
				return (FAILURE);
			}
			++ops_i;
		}
		++instructions;
	}
	return (SUCCESS);
}

int					fill_instructions(char ***instructions, int *inst_size)
{
	*inst_size = 0;
	*instructions = NULL;
	;
	if (get_instructions(instructions, inst_size) == FAILURE ||
		check_instructions(*instructions) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
