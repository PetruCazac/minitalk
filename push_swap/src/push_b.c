/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:51:12 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/13 08:40:21 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push_b(t_dlist **a, t_dlist **b)
{
	int		max;
	int		med;
	int		j;
	
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
	// sort_small(a);
	// push_back(a, b);
}
