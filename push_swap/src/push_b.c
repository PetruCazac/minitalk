/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:51:12 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/13 15:22:37 by pcazac           ###   ########.fr       */
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
		move_element(move_calculate(a, b), a, b);
	final_rotate(a);
}
