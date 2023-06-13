/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:43:00 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/13 13:51:16 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	moves_b(t_dlist **b)
{
	int		i;
	t_dlist	*temp;
	int		m;

	i = 0;
	temp = *b;
	m = count_list(b);
	while (i <= (m / 2) && temp)
	{
		temp->moves_b = i;
		temp->direction = 1;
		i++;
		temp = temp->end;
	}
	i = m / 2;
	while (i > 0 && temp)
	{
		temp->moves_b = i;
		temp->direction = 2;
		i--;
		temp = temp->end;
	}
}

void	moves_a(t_dlist **a)
{
	int		i;
	t_dlist	*temp;
	int		m;

	i = 0;
	temp = *a;
	m = count_list(a);
	while (i <= (m / 2)&& temp)
	{
		temp->moves_a = i;
		temp->direction = 1;
		i++;
		temp = temp->end;
	}
	i = m / 2;
	while (i > 0 && temp)
	{
		temp->moves_a = i;
		temp->direction = 2;
		i--;
		temp = temp->end;
	}
}

void	find_place(t_dlist **a, t_dlist **b)
{
	t_dlist	*ta;
	t_dlist	*tb;
	t_dlist	*pos;

	tb = *b;
	pos = NULL;
	while (tb)
	{
		ta = *a;
		tb->bigger = ta;
		while (ta)
		{
			if (tb->index < ta->index)
			{
				pos = tb->bigger;
				tb->bigger = ta;
				if (pos->index < ta->index && pos->index > tb->index)
					tb->bigger = pos;
			}
			ta = ta->end;
		}
		tb = tb->end;
	}
}

t_dlist	*choose_smaller(t_dlist **b)
{
	t_dlist	*element;
	t_dlist	*tb;

	tb = *b;
	tb->moves = tb->moves_b + tb->bigger->moves_a;
	element = tb;
	while (tb)
	{
		if (tb->moves < element->moves)
			element = tb;
		tb = tb->end;
		if (tb)
			tb->moves = tb->moves_b + tb->bigger->moves_a;
	}
	return (element);
}
// The function will find calculate the optimum movement for each element in each stack
// it will then return the element to be brought on top of the stack from a and b.
t_dlist	*move_calculate(t_dlist **a, t_dlist **b)
{
	moves_b(b);
	moves_a(a);
	find_place(a, b);
	return (choose_smaller(b));
}
