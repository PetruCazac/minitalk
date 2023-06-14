/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:43:00 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/14 08:30:37 by pcazac           ###   ########.fr       */
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
// Takes into account the common moves. 
void	calculate_moves(t_dlist **b)
{
	t_dlist	*element;
	t_dlist	*tb;
	int		up;
	int		pos_up;
	int		down;
	int		pos_down;

	up = 0;
	pos_up = 0;
	down = 0;
	pos_down = 0;
	tb = *b;
	while (tb)
	{
		// Calculating the up common movements
		tb->mv_up = up;
		tb->pos->mv_up = pos_up;
		while (tb->mv_up || up)
		{
			up--;
			pos_up--;
			tb->cm_up++;
		}
		if (up && !pos_up)
		{
			tb->pos->rest_up = 0;
			tb->rest_up = up - tb->cm_up;
		}
		else if (!up && pos_up)
		{
			tb->rest_up = 0;
			tb->pos->rest_up = up - tb->cm_up;
		}
		else if (!up && !pos_up)
		{
			tb->rest_up = 0;
			tb->pos->rest_up = 0;
		}
		// Calculating the down common movements
		tb->mv_down = down;
		tb->pos->mv_down = pos_down;
		while (tb->mv_down || down)
		{
			down--;
			pos_down--;
			tb->cm_down++;
		}
		if (down && !pos_down)
		{
			tb->pos->rest_down = 0;
			tb->rest_down = down - tb->cm_down;
		}
		else if (!down && pos_down)
		{
			tb->rest_down = 0;
			tb->pos->rest_down = down - tb->cm_down;
		}
		else if (!down && !pos_down)
		{
			tb->rest_down = 0;
			tb->pos->rest_down = 0;
		}
		// Calculating the closest position for direct movement
		if ((tb->mv_up + tb->pos->mv_down) < (tb->mv_down + tb->pos->mv_up))
		{
			tb->mv_down = 0;
			tb->pos->mv_up = 0;
		}
		else if ((tb->mv_up + tb->pos->mv_down) > (tb->mv_down + tb->pos->mv_up))
		{
			tb->mv_up = 0;
			tb->pos->mv_down = 0;
		}
		tb = tb->end;
	}
}

int	compare_move(t_dlist **b)
{
	t_dlist	*tb;
	int	combined_up;
	int	combined_down;

	tb = *b;
	combined_up = tb->cm_up + tb->pos->rest_up + tb->rest_up;
	combined_down = tb->cm_down + tb->pos->rest_down + tb->rest_down;
	if (combined_up > combined_down)
	{
		tb->cm_up = 0;
		tb->pos->rest_up = 0;
		tb->rest_up = 0;
		return (combined_down);
	}
	else if (combined_up <= combined_down)
	{
		tb->cm_down = 0;
		tb->pos->rest_down = 0;
		tb->rest_down = 0;
		return (combined_up);
	}
}

void	choose_smaller(t_dlist **b)
{
	t_dlist	*temp;
	t_dlist	*tb;
	int		combined_moves;
	int		simple_moves;

	tb = *b;
	temp = *b;
	combined_moves = 0;
	simple_moves = 0;
	while (tb)
	{
		combined_moves = compare_move(tb);
		simple_moves = tb->mv_down + tb->mv_up + tb->pos->mv_down + tb->pos->mv_up;
		if (combined_moves < simple_moves)
		{
			tb->mv_down = 0;
			tb->mv_up = 0;
			tb->pos->mv_down = 0;
			tb->pos->mv_up = 0;
			tb->mv = combined_moves;
		}
		else if (combined_moves >= simple_moves)
		{
			tb->cm_down = 0;
			tb->cm_up = 0;
			tb->pos->cm_down = 0;
			tb->pos->cm_up = 0;
			tb->rest_down = 0;
			tb->rest_up = 0;
			tb->pos->rest_down = 0;
			tb->pos->rest_up = 0;
			tb->mv = simple_moves;
	
		}
		
		tb = tb->end;
	}
}

t_dlist	*element_finder(t_dlist **b)
{
	t_dlist	*tb;

}
// The function will find calculate the optimum movement for each element in each stack
// it will then return the element to be brought on top of the stack from a and b.
t_dlist	*move_calculate(t_dlist **a, t_dlist **b)
{
	moves(b);
	moves(a);
	find_place(a, b);
	calculate_moves(b);
	choose_smaller(b);
	return (element_finder(b));
}
