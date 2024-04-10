/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_smaller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:53:58 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/19 12:36:26 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	compare_move(t_dlist **b)
{
	t_dlist	*tb;
	int		combined_up;
	int		combined_down;

	tb = *b;
	combined_up = tb->cm_up + tb->pos_up + tb->rest_up;
	combined_down = tb->cm_down + tb->pos_down + tb->rest_down;
	if (combined_up > combined_down)
	{
		tb->cm_mv = combined_down;
		tb->cm_dir = 22;
	}
	else if (combined_up <= combined_down)
	{
		tb->cm_mv = combined_up;
		tb->cm_dir = 11;
	}
	return ;
}

t_dlist	**choose_smaller(t_dlist **b, t_dlist **elem)
{
	t_dlist	*element;
	t_dlist	*tb;

	tb = *b;
	element = *b;
	while (tb)
	{
		compare_move(&tb);
		if (tb->mv > tb->cm_mv)
		{
			tb->mv = tb->cm_mv;
			tb->dir = tb->cm_dir;
		}
		if (tb->mv < element->mv)
			element = tb;
		tb = tb->end;
	}
	*elem = element;
	return (elem);
}
