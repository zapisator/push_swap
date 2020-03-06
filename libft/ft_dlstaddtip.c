/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddtip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:26:13 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 17:35:14 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	It finds the last node of the linked list, and returns pointer to it.
*/

void				ft_dlstaddtip(t_dlist **head, t_dlist *new)
{
	t_dlist			*last;

	if (head && new)
	{
		if (*head)
		{
			last = (*head)->prev;
			new->prev = last;
			new->next = *head;
			(*head)->prev = new;
			last->next = (*head)->prev;
		}
		else
		{
			*head = new;
			new->next = new;
			new->prev = new;
		}
	}
	return ;
}
