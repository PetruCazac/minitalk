/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:51:12 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/19 12:45:28 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	prepush(t_dlist **a, t_dlist **b)
{
	int		max_lim;
	int		count;
	int		segment;

	count = 0;
	segment = (find_max(a))->index / 3;
	max_lim = segment;
	while (count_list(a) != 3)
	{
		if ((*a)->index >= (max_lim - segment) && (*a)->index < max_lim)
		{
			push(a, b, 'b');
			if (count < (segment / 2))
				rotate(b, 'b');
			count++;
		}
		else if (count == segment)
		{
			max_lim = max_lim + segment;
			count = 0;
		}
		else
			rotate(a, 'a');
	}
}
