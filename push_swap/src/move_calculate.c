/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:43:00 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/14 15:14:58 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	moves(t_dlist **stack)
{
	int		i;
	t_dlist	*temp;
	int		m;

	i = 0;
	temp = *stack;
	m = count_list(stack);
	while (i <= m && temp)
	{
		temp->mv_up = i;
		i++;
		temp = temp->end;
	}
	i = m;
	temp = *stack;
	while (i > 0 && temp)
	{
		temp->mv_down = i;
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
		tb->pos = ta;
		while (ta)
		{
			if (tb->index < ta->index)
			{
				pos = tb->pos;
				tb->pos = ta;
				if (pos->index < ta->index && pos->index > tb->index)
					tb->pos = pos;
			}
			ta = ta->end;
		}
		tb = tb->end;
	}
}


void	clean_moves(t_dlist	**stack)
{
	t_dlist *temp;

	temp = *stack;
	while (temp)
	{
		temp->mv = 0;
		temp->mv_up = 0;
		temp->mv_down= 0;
		temp->cm_up = 0;
		temp->cm_down = 0;
		temp->rest_up = 0;
		temp->rest_down = 0;
		temp->dir = 0;
		temp->pos_up = 0;
		temp->pos_down = 0;
		temp = temp->end;
	}
}

t_dlist	*move_calculate(t_dlist **a, t_dlist **b)
{
	clean_moves(a);
	clean_moves(b);
	moves(b);
	moves(a);
	find_place(a, b);
	calculate_moves(b);
	return (choose_smaller(b));
}
