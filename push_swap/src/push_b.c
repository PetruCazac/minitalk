/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:51:12 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/14 10:37:59 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	move_both(t_dlist *element, t_dlist **a, t_dlist **b)
{
	while (element->cm_down && element->cm_down)
	{
		if (element->cm_up != 0)
		{
			rotate_both(a, b);
			element->cm_up--;
		}
		else if (element->cm_down != 0)
		{
			rrotate_both(a, b);
			element->cm_down--;
		}
	}
	while (element->rest_up != 0)
	{	
		rotate(b, 'b');
		element->rest_up--;
	}
	while (element->rest_down != 0)
	{	
		rrotate(b, 'b');
		element->rest_down--;
	}
	while (element->pos->rest_up != 0)
	{	
		rotate(b, 'b');
		element->pos->rest_up--;
	}
	while (element->pos->rest_down != 0)
	{	
		rrotate(b, 'b');
		element->pos->rest_down--;
	}
	push(b, a, 'a');
}

void	move_element(t_dlist *element, t_dlist **a, t_dlist **b)
{
	while ((*b) != element)
	{
		if (element->mv_up != 0 && element->mv_down == 0 && (*b) != element)
			rotate(b, 'b');
		else if (element->mv_down != 0 && element->mv_up == 0 && (*b) != element)
			rrotate(b, 'b');
	}
	while ((*a) != element->pos)
	{
		if (element->pos->mv_up != 0 && element->pos->mv_down == 0 && (*a) != element->pos)
			rotate(a, 'a');
		else if (element->pos->mv_down != 0 && element->pos->mv_up == 0 && (*a) != element->pos)
			rrotate(a, 'a');
	}
	push(b, a, 'a');
}

void	choose_move(t_dlist *element, t_dlist **a, t_dlist **b)
{
	if (element->dir == 1)
		move_both(element, a, b);
	if (element->dir == 2)
		move_element(element, a, b);
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

void	push_b(t_dlist **a, t_dlist **b)
{
	int		max;
	int		med;
	int		j;
	// t_dlist	*element;
	
	max = (find_max(a))->index;
	med = max / 2;
	j = count_list(a);
	while (j != 3)
	{
		if ((*a)->index == 0 || (*a)->index == max || (*a)->index == med)
			rotate(a, 'a');
		else
			push(a, b, 'b');
		j = count_list(a);
	}
	sort_small(a);
	while (count_list(b) != 0)
		choose_move(move_calculate(a, b), a, b);
	final_rotate(a);
}
