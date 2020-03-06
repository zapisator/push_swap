/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:52:50 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 16:17:58 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**								CHECK
*/

static int			count_numbers(char **cur_param, int *counter_of_nbrs)
{
	char			*str;
	int				max_digits;

	while (*cur_param)
	{
		max_digits = 10;
		str = *cur_param;
		if (*str == '-' || *str == '+')
		{
			++max_digits;
			++str;
		}
		while (*str && max_digits--)
			if (!(ft_isdigit(*str++)))
				return (FAILURE);
		++(*counter_of_nbrs);
		++cur_param;
	}
	return (SUCCESS);
}

void				free_params(char ***params, int size)
{
	char			***ankor;
	char			**curr;

	ankor = params;
	if (size && params)
	{
		while (size-- && *params)
		{
			curr = *params;
			while (*curr)
				free(*curr++);
			ft_memdel((void **)params++);
		}
		free((void *)ankor);
	}
	return ;
}

int					check_params(char ***params)
{
	int				counter_of_nbrs;
	char			***curr;

	counter_of_nbrs = 0;
	curr = params;
	while (*curr)
		if (count_numbers(*curr++, &counter_of_nbrs) == FAILURE)
			return (FAILURE);
	return (counter_of_nbrs);
}

/*
**								READ
*/

int					read_params(char ***params, char **argv, int argc)
{
	int				i;
	int				result;

	ft_bzero(params, argc * sizeof(*params));
	result = SUCCESS;
	i = argc - 1;
	*(params + argc - 1) = NULL;
	while (--argc)
	{
		if (!(*params = ft_strsplit(*(++argv), ' ')))
		{
			free_params(params - (i - argc + 1), i - argc);
			result = FAILURE;
			break ;
		}
		++params;
	}
	return (result);
}
