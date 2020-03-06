/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nbrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:16:10 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/06 18:27:44 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int			check_ou_flow(char *str)
{
	size_t			nbr_len;
	char			nbr_str[64 + 1];

	ft_bzero((void *)nbr_str, 64 + 1);
	nbr_len = ft_strlen(str);
	if (nbr_len > 11)
		return (FAILURE);
	else if (nbr_len >= 10)
	{
		(void)ft_imaxtostr(nbr_str, ft_atoi(str), 10, 1);
		if (ft_strcmp(str, nbr_str))
			return (FAILURE);
	}
	return (SUCCESS);
}

static int			transform_nbr_str(char ****params, int *nbrs)
{
	char			***ar_of_str_ar;
	char			**str_ar;

	ar_of_str_ar = *params;
	while (*ar_of_str_ar)
	{
		str_ar = *ar_of_str_ar;
		while (*str_ar)
		{
			if (check_ou_flow(*str_ar) == FAILURE)
				return (FAILURE);
			*nbrs++ = ft_atoi(*str_ar);
			++str_ar;
		}
		++ar_of_str_ar;
	}
	return (SUCCESS);
}

static int			check_replays(int *nbrs, int counter_of_nbrs)
{
	int				i;

	i = 0;
	while (--counter_of_nbrs)
	{
		if (*(nbrs + i) == *(nbrs + i + 1))
			return (FAILURE);
		++i;
	}
	return (SUCCESS);
}

int					investigate_nbrs(int **nbrs, int *counter_of_nbrs)
{
	int				*nbrs_cpy;

	if (!(nbrs_cpy = (int *)ft_memalloc(*counter_of_nbrs * sizeof(*nbrs_cpy))))
	{
		ft_putendl_fd("Error", STDERR);
		ft_memdel((void **)nbrs);
		return (FAILURE);
	}
	ft_memcpy(nbrs_cpy, *nbrs, *counter_of_nbrs * sizeof(*nbrs_cpy));
	ft_quicksort(nbrs_cpy, *counter_of_nbrs);
	if (check_replays(nbrs_cpy, *counter_of_nbrs) == FAILURE)
	{
		ft_putendl_fd("Error", STDERR);
		ft_memdel((void **)nbrs);
		free(nbrs_cpy);
		return (FAILURE);
	}
	return (SUCCESS);
}

int					fill_nbrs(int argc, char **argv,
						int **nbrs, int *counter_of_nbrs)
{
	char			***params;

	*counter_of_nbrs = 0;
	params = NULL;
	if (!(params = (char ***)ft_memalloc(argc * sizeof(char **))) ||
		read_params(params, argv, argc) == FAILURE)
	{
		free(params);
		return (FAILURE);
	}
	if ((*counter_of_nbrs = check_params(params)) == FAILURE ||
			!(*nbrs = (int *)ft_memalloc((*counter_of_nbrs + 1) * sizeof(int)))
			|| transform_nbr_str(&params, *nbrs) == FAILURE)
	{
		ft_putendl_fd("Error", STDERR);
		free_params(params, argc);
		return (FAILURE);
	}
	free_params(params, argc);
	return (SUCCESS);
}
