/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculate2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:20:55 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/14 23:20:41 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	moves_up(t_dlist **b)
{
	t_dlist	*tb;
	int		up;
	int		pos_up;

	tb = *b;
	up = tb->mv_up;
	pos_up = tb->pos->mv_up;
	while (up != 0 && pos_up != 0)
	{
		up--;
		pos_up--;
		tb->cm_up++;
	}
	if (up != 0 && pos_up == 0)
		tb->rest_up = up;
	else if (up == 0 && pos_up != 0)
		tb->pos_up = pos_up;
}

void	moves_down(t_dlist **b)
{
	t_dlist	*tb;
	int		down;
	int		pos_down;

	tb = *b;
	down = tb->mv_down;
	pos_down = tb->pos->mv_down;
	while (down != 0 && pos_down != 0)
	{
		down--;
		pos_down--;
		tb->cm_down++;
	}
	if (down != 0 && pos_down == 0)
		tb->rest_down = down;
	else if (down == 0 && pos_down != 0)
		tb->pos_down = pos_down;
}

void	moves_solo(t_dlist **b)
{
	t_dlist	*tb;

	tb = *b;
	if ((tb->mv_up + tb->pos->mv_down) <= (tb->mv_down + tb->pos->mv_up))
	{
		tb->mv = tb->mv_up + tb->pos->mv_down;
		tb->dir = 21;
	}
	else if ((tb->mv_up + tb->pos->mv_down) > (tb->mv_down + tb->pos->mv_up))
	{
		tb->mv = tb->mv_down + tb->pos->mv_up;
		tb->dir = 12;
	}
}

void	calculate_moves(t_dlist **b)
{
	t_dlist	*tb;

	tb = *b;
	while (tb)
	{
		moves_up(&tb);
		moves_down(&tb);
		moves_solo(&tb);
		tb = tb->end;
	}
}
