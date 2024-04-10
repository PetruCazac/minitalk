/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:51:12 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/19 14:56:14 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	move_both(t_dlist **elem, t_dlist **a, t_dlist **b)
{
	t_dlist	*element;

	element = *elem;
	while ((*b) != element && (*a) != element->pos)
	{
		if (element->dir == 11)
			rotate_both(a, b);
		else if (element->dir == 22)
			rrotate_both(a, b);
	}
	while ((*b) != element && element->dir == 11)
		rotate(b, 'b');
	while ((*a) != element->pos && element->dir == 11)
		rotate(a, 'a');
	while ((*b) != element && element->dir == 22)
		rrotate(b, 'b');
	while ((*a) != element->pos && element->dir == 22)
		rrotate(a, 'a');
	push(b, a, 'a');
}

void	move_element(t_dlist **elem, t_dlist **a, t_dlist **b)
{
	t_dlist	*element;

	element = *elem;
	while ((*b) != element)
	{
		if (element->dir == 21 && (*b) != element)
			rotate(b, 'b');
		else if (element->dir == 12 && (*b) != element)
			rrotate(b, 'b');
	}
	while ((*a) != element->pos)
	{
		if (element->dir == 12 && (*a) != element->pos)
			rotate(a, 'a');
		else if (element->dir == 21 && (*a) != element->pos)
			rrotate(a, 'a');
	}
	push(b, a, 'a');
}

void	make_move(t_dlist **elem, t_dlist **a, t_dlist **b)
{
	t_dlist	*element;

	element = *elem;
	if (element->dir == 11 || element->dir == 22)
		move_both(&element, a, b);
	if (element->dir == 12 || element->dir == 21)
		move_element(&element, a, b);
	*elem = NULL;
	return ;
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

void	push_b(t_dlist **a, t_dlist **b, t_dlist **elem)
{
	prepush(a, b);
	sort_small(a, b, elem);
	while (count_list(b) != 0)
	{
		make_move(move_calculate(a, b, elem), a, b);
		*elem = NULL;
	}
	final_rotate(a);
}
