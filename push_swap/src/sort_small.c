/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:02:32 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/19 16:44:38 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort_3(t_dlist **list_a);
void	sort_2(t_dlist **list_a);

void	sort_small(t_dlist **list_a, t_dlist **list_b, t_dlist **elem)
{
	int		i;

	if (sort_check(list_a))
		return ;
	while (count_list(list_a) > 3)
	{
		if (*list_a == find_max(list_a))
			rotate(list_a, 'a');
		push(list_a, list_b, 'b');
	}
	i = count_list(list_a);
	if (i < 3)
		return (sort_2(list_a));
	sort_3(list_a);
	if (!list_b)
		return ;
	else if (list_b)
		push_b(list_a, list_b, elem);
	return ;
}

void	sort_3(t_dlist **list_a)
{
	int	a;
	int	b;
	int	c;

	a = (*list_a)->number;
	b = (*list_a)->next->number;
	c = (*list_a)->next->next->number;
	if ((a > b && a < c) || (a > b && a > c && b > c) || (a < b && a < c))
		swap(list_a, 'a');
	a = (*list_a)->number;
	b = (*list_a)->next->number;
	c = (*list_a)->next->next->number;
	if ((a < b && b > c && a > c))
		rrotate(list_a, 'a');
	if ((a > b && a > c && b < c))
		rotate(list_a, 'a');
}

void	sort_2(t_dlist **list_a)
{
	t_dlist	*temp;

	temp = *list_a;
	if (temp->number > temp->next->number)
		swap(list_a, 'a');
	return ;
}
