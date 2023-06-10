/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:27:24 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/10 21:08:18 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_dlist	*copy_list(t_dlist **a)
{
	t_dlist	*b;
	t_dlist	*temp;

	temp = (*a);
	while (temp->next)
	{
		ft_dlstadd_back(b, ft_dlstnew(temp->number));
		temp = temp->next;
	}
	return (b);
}

void	insert(t_dlist	**start, t_dlist **min)
{
	
}

void	presort(t_dlist **a)
{
	t_dlist	*b;
	t_dlist	*min;
	t_dlist	*pos;

	b = copy_list(a);
	pos = b;
	min = find_min(&b);
	// sorting algorithm insert algorithm
	while (sort_check(&b))
	{
		while (b)
		{
			insert(pos, min);
			pos = min;
			b = pos;
			b = b->end;
		}
	}
}
