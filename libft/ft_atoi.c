/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:32:00 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 16:56:30 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function accepts a string and processes it sequentially, expecting that
** this number is within an int. Expected format: a number of whitespace
** characters, then the sign of a number, numbers is possible. All further
** characters are not parsable. Especially if the sequence of digits is left
** with zeros, then all zeros except one are skipped.
**	Returns the converted number if it is within int, otherwise 0.
*/

static const char	*ft_spskip(const char *str)
{
	while (ft_isspace((int)(*str)))
		str++;
	return (str);
}

static const char	*ft_fndsgn(const char *str, int *sgn)
{
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			*sgn = (-1);
		str++;
	}
	return (str);
}

static const char	*ft_is0(const char *str)
{
	while (ft_isdigit(*str) && (*str == '0') && (*(str + 1) == '0'))
		str++;
	return (str);
}

int					ft_atoi(const char *str)
{
	long int		nbr;
	int				sgn;
	int				ovr;

	nbr = 0;
	sgn = 1;
	ovr = 10;
	if (str)
	{
		str = ft_is0(ft_fndsgn(ft_spskip(str), &sgn));
		while (ft_isdigit((int)(*str)) && ovr--)
		{
			nbr = (10 * nbr) + (*str++ - '0');
			if (nbr < INT_MIN || INT_MAX < nbr)
				break ;
		}
	}
	return (nbr * sgn);
}
