/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:51:12 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/11 18:59:03 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// It has to take the indexed list a and divides it in n pieces that are to be used to forme a K sape of the graph.
// Start first by moving all of the elements, except 3, sort those 3 and bring back all the other

// The algorithm has to check the numbers that are not to be pushed, maybe make a list of all the numbers that are 
// not in order and push only these numbers in the stack b in a k shape this minimizng the movements 

void	push_b(t_dlist **a, t_dlist **b, int segments)
{
	int	i;
	int	j;
	t_dlist	*temp;
	
	j = 1;
	i = 0;
	i = count_list(a);
	i = i / segments;
	while (count_list(a) != 3)
	{
		if ((*a)->index <= j)
		{
			push(a, b, 'b');
			rrotate(b, 'b');
			i++;
			j++;
		}
		else if ((*a)->index <= i && (*a)->index > j)
		{
			push(a, b, 'b');
			i++;
			j++;
		}
		else
			rotate(a, 'a');
	}
	temp = *b;
	while (temp)
	{
		ft_printf("%i\n", temp->number);
		temp = temp->end;
	}
}
