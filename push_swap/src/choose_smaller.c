/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_smaller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:53:58 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/14 15:22:39 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	simple_move(t_dlist **b, int moves)
{
	t_dlist	*tb;

	tb = *b;
	tb->mv = moves;
	tb->dir = 11;
}

void	combined_move(t_dlist **b, int moves)
{
	t_dlist	*tb;

	tb = *b;
	tb->mv = moves;
	tb->dir = 22;
}

t_dlist	*choose_smaller(t_dlist **b)
{
	t_dlist	*element;
	t_dlist	*tb;
	int		combined;
	int		simple;

	tb = *b;
	element = *b;
	combined= 0;
	simple = 0;
	while (tb)
	{
		combined = compare_move(tb);
		simple = tb->mv_down + tb->mv_up + tb->pos->mv_down + tb->pos->mv_up;
		if (combined < simple)
			combined_move(&tb, combined);
		else if (combined >= simple)
			simple_move(&tb, simple);
		if(tb->mv < element->mv)
			element = tb;
		tb = tb->end;
	}
	return (element);
}

int	compare_move(t_dlist *tb)
{
	int	combined_up;
	int	combined_down;

	combined_up = tb->cm_up + tb->pos_up + tb->rest_up;
	combined_down = tb->cm_down + tb->pos_down + tb->rest_down;
	if (combined_up > combined_down)
	{
		tb->cm_up = 0;
		tb->pos_up = 0;
		tb->rest_up = 0;
		return (combined_down);
	}
	else if (combined_up <= combined_down)
	{
		tb->cm_down = 0;
		tb->pos_down = 0;
		tb->rest_down = 0;
		return (combined_up);
	}
	return (-1);
}
