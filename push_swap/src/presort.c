/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:27:24 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/11 08:28:59 by pcazac           ###   ########.fr       */
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

void	insert(t_dlist	**head, t_dlist **temp)
{
	t_dlist	*min;
	t_dlist	*start;

	min = *temp;
	start = *head;
	min->previous->next = min->next;
	min->previous->end = min->end;
	min->next->previous = min->previous;
	min->next = start->next;
	min->end = start->end;
	min->previous = start;
	start->next = min;
}

void	assign(t_dlist **a, *t_dlist **b)
{
	
}

void	presort(t_dlist **a)
{
	t_dlist	*b;
	t_dlist	*min;
	t_dlist	*pos;

	b = copy_list(a);
	pos = b;
	// sorting algorithm insert algorithm
	while (sort_check(&b))
	{
		while (b)
		{
			min = find_min(&pos);
			insert(&pos, &min);
			pos = min;
			b = pos->end;
		}
	}
}
