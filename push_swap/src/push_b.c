/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:51:12 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/12 19:09:30 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// It has to take the indexed list a and divides it in n pieces that are to be used to forme a K sape of the graph.
// Start first by moving all of the elements, except 3, sort those 3 and bring back all the other

// The algorithm has to check the numbers that are not to be pushed, maybe make a list of all the numbers that are 
// not in order and push only these numbers in the stack b in a k shape this minimizng the movements 

void	push_b(t_dlist **a, t_dlist **b)
{
	t_dlist	*max;
	int		i;
	int		j;

	max = find_max(a);
	j = count_list(a);
	i = max->index / 2;
	while (j != 3)
	{
		if ((*a)->index != 0 && (*a)->index != max->index && (*a)->index != i)
			push(a, b, 'b');
		else
			rotate(a, 'a');
		j = count_list(a);
	}
	// sort_small(a);
	// push_back(a, b);
}
