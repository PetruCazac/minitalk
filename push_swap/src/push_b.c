/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:51:12 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/12 10:23:26 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// It has to take the indexed list a and divides it in n pieces that are to be used to forme a K sape of the graph.
// Start first by moving all of the elements, except 3, sort those 3 and bring back all the other

// The algorithm has to check the numbers that are not to be pushed, maybe make a list of all the numbers that are 
// not in order and push only these numbers in the stack b in a k shape this minimizng the movements 

void	push_b(t_dlist **a, t_dlist **b, int segments)
{
	t_dlist	*min;
	t_dlist	*max;
	int		i;
	int		j;
	t_dlist	*temp;
	
	min = find_min(a);
	max = find_max(a);
	i = count_list(a);
	j = count_list(a);
	i = i / segments;
	while  (j != 3)
	{
		if ((*a)->number == min->number || (*a)->number == max->number || (*a)->number == (max->number / 2))
			rotate(a, 'a');
		else
			push(a, b, 'b');
		j = count_list(a);
	}
	temp = *b;
	while (temp)
	{
		ft_printf("b stack: %i\n", temp->number);
		temp = temp->end;
		i++;
	}
}

		// if ((*a)->index < j)
		// {
		// 	push(a, b, 'b');
		// 	rrotate(b, 'b');
		// 	i++;
		// 	j++;
		// }
		// else if ((*a)->index <= i && (*a)->index > j)
		// {
		// 	push(a, b, 'b');
		// 	i++;
		// 	j++;
		// }
		// else
		// 	rotate(a, 'a');