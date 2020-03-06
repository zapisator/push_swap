/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:38:42 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 16:12:05 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int					usage_ps(void)
{
	ft_putendl(""
			"Usage:\t./push_swap [options] <args ...>\n"
			"Example:\n"
				"\t./push_swap <args ...> | ./checker <args ...>");
	return (FAILURE);
}

int					usage_ch(void)
{
	ft_putendl(""
			"Usage:\t./checker [options] <args ...>\n"
			"  options:"
			"\t-v\t\tvisualizer\n"
			"Example:\n"
				"\t./checker -f [file_name] <args ...>");
	return (FAILURE);
}
