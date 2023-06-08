/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:02:32 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/08 13:44:06 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort_3(t_dlist **list_a);
void	sort_2(t_dlist **list_a);

void	sort_small(t_dlist **list_a)
{
	int		i;
	t_dlist	*list_b;

	list_b = NULL;
	if (sort_check(list_a))
		return ;
	i = count_list(list_a);
	if (i < 3)
		return (sort_2(list_a));
	presort(list_a);
	push_min_max(list_a, &list_b);
	sort_3(list_a);
	if (!list_b)
		return ;
	sort_back(list_a, &list_b);
	return ;
}

sort_back(t_dlist **list_a, t_dlist **list_b)
{
	t_dlist	*a;
	t_dlist	*b;

	a = *list_a;
	b = *list_b;
	while (a->number > b->number)
	{
		
		
	}
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
