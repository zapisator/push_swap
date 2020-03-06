/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:38:42 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 12:11:07 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int			do_operations(t_check *ch, char **instructions,
		t_dlist **stack_a, t_dlist **stack_b)
{
	int				ops_i;

	if (!instructions || (!stack_a && !stack_b))
		return (FAILURE);
	while (*instructions)
	{
		ops_i = get_instruction_index(instructions);
		if (ops_i == 0 || ops_i == 5 || ops_i == 8)
			(*op_dispatcher)(ops_i)(stack_a, NULL);
		else if (ops_i == 1 || ops_i == 6 || ops_i == 9)
			(*op_dispatcher)(ops_i)(NULL, stack_b);
		else if (ops_i == 2 || ops_i == 3 || ops_i == 7 || ops_i == 10)
			(*op_dispatcher(ops_i))(stack_a, stack_b);
		else if (ops_i == 4)
			(*op_dispatcher(ops_i))(stack_b, stack_a);
		else
			(*op_dispatcher(ops_i))(NULL, NULL);
		if (ch->isvisualized)
			visualize(ch);
		++instructions;
	}
	return (SUCCESS);
}

static void			last_check(t_dlist *stack_a, t_dlist *stack_b)
{
	t_dlist			*curr;

	curr = stack_a;
	if (!stack_b)
	{
		while (curr->next != stack_a)
		{
			if (*((int *)curr->content) > *((int *)curr->next->content))
			{
				ft_putendl("KO");
				return ;
			}
			curr = curr->next;
		}
		ft_putendl("OK");
		return ;
	}
	ft_putendl("KO");
	return ;
}

void				checker_free(t_check *ch)
{
	free(ch->nbrs);
	free(ch->instructions);
	ft_dlstdel(&ch->stack_a, ft_dlstcontentdel);
	ft_dlstdel(&ch->stack_b, ft_dlstcontentdel);
	return ;
}

/*
**								MAIN
*/

int					main(int argc, char **argv)
{
	t_check			ch;

	if (argc < 2)
		return (usage_ch());
	if (!ft_strcmp(*(argv + 1), "-v"))
	{
		printf("-v option\n");
		--argc;
		++argv;
		ch.isvisualized = !!TRUE;
	}
	else
		ch.isvisualized = !TRUE;
	if (fill_nbrs(argc, argv, &ch.nbrs, &ch.counter_of_nbrs) != FAILURE &&
			fill_instructions(&ch.instructions, &ch.inst_size) != FAILURE &&
			make_stacks(&ch.nbrs, ch.counter_of_nbrs, &ch.stack_a, &ch.stack_b)
		!= FAILURE)
	{
		do_operations(&ch, ch.instructions, &ch.stack_a, &ch.stack_b);
		last_check(ch.stack_a, ch.stack_b);
	}
	checker_free(&ch);
	return (SUCCESS);
}
