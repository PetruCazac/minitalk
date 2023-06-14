/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:51:12 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/14 13:00:22 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	move_element(t_dlist *element, t_dlist **a, t_dlist **b)
{
	while ((*b) != element)
	{
		if (element->direction == 1 && (*b) != element)
			rotate(b, 'b');
		else if (element->direction == 2 && (*b) != element)
			rrotate(b, 'b');
	}
	while ((*a) != element->bigger)
	{
		if (element->bigger->direction == 1 && (*a) != element->bigger)
			rotate(a, 'a');
		else if (element->bigger->direction == 2 && (*a) != element->bigger)
			rrotate(a, 'a');
	}
	push(b, a, 'a');
}

void	final_rotate(t_dlist **a)
{
	int		i;
	t_dlist	*temp;
	int		m;

	m = count_list(a);
	i = 0;
	temp = *a;
	while (temp->index != 0)
	{
		temp = temp->end;
		i++;
	}
	if (i <= m / 2)
	{
		while ((*a)->index != 0)
			rotate(a, 'a');
	}
	else if (i > m / 2)
	{
		while ((*a)->index != 0)
			rrotate(a, 'a');
	}
}

void	prepush(t_dlist **a, t_dlist **b)
{
	int		max_lim;
	int		min_lim;
	int		count;
	int		segment;

	count = 0;
	min_lim = 0;
	segment = (find_max(a))->index / 3;
	max_lim = segment;
	while (count_list(a) != 3)
	{
		if ((*a)->index >= min_lim && (*a)->index < max_lim)
		{
			push(a, b, 'b');
			if (count < (segment / 2))
				rotate(b, 'b');
			count++;
		}
		else if (count == segment)
		{
			min_lim = min_lim + segment;
			max_lim = max_lim + segment;
			count = 0;
		}
		else
			rotate(a, 'a');
	}
}

void	push_b(t_dlist **a, t_dlist **b)
{
	prepush(a, b);
	sort_small(a);
	while (count_list(b) != 0)
		move_element(move_calculate(a, b), a, b);
	final_rotate(a);
}
