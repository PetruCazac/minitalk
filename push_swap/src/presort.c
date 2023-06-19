/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:27:24 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/19 12:39:24 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	copy_list(t_dlist **a, t_dlist **b)
{
	t_dlist	*temp;

	temp = (*a);
	while (temp)
	{
		ft_dlstadd_back(b, ft_dlstnew(temp->number));
		temp = temp->end;
	}
	return ;
}

void	insert(t_dlist	**head, t_dlist **temp, t_dlist **list)
{
	t_dlist	*min;
	t_dlist	*start;

	if (*head == *temp)
		return ;
	min = *temp;
	start = *head;
	min->prev->next = min->next;
	min->prev->end = min->end;
	min->next->prev = min->prev;
	min->next = start;
	min->end = start;
	min->prev = start->prev;
	min->prev->next = min;
	if (min->prev->end)
		min->prev->end = min;
	start->prev = min;
	while (start->end)
		start = start->end;
	start = start->next;
	*list = start;
}

void	assign(t_dlist **a, t_dlist **b)
{
	int		i;
	t_dlist	*b_temp;
	t_dlist	*a_temp;

	i = 0;
	b_temp = *b;
	while (b_temp)
	{
		b_temp->index = i;
		i++;
		b_temp = b_temp->end;
	}
	b_temp = *b;
	while (b_temp)
	{	
		a_temp = *a;
		while (a_temp)
		{
			if (a_temp->number == b_temp->number)
				a_temp->index = b_temp->index;
			a_temp = a_temp->end;
		}
		b_temp = b_temp->end;
	}
	return (ft_dlstclear(b));
}

void	presort(t_dlist **a, t_dlist **b)
{
	t_dlist	*min;
	t_dlist	*pos;

	copy_list(a, b);
	pos = *b;
	while (!sort_check(b))
	{
		min = find_min(&pos);
		insert(&pos, &min, b);
		pos = min;
		pos = pos->end;
	}
	assign(a, b);
	return ;
}
