/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:01:40 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/10 19:47:06 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	count_list(t_dlist **list)
{
	t_dlist	*temp;
	int		i;

	i = 0;
	temp = *list;
	while(temp)
	{
		i++;
		temp = temp->end;
	}
	return (i);
}

t_dlist	*find_min(t_dlist **list)
{
	t_dlist	*temp;
	t_dlist	*min;
	int		i;

	temp = *list;
	min = *list;
	i = temp->number;
	while (temp)
	{
		if (i > temp->number)
		{
			i = temp->number;
			min = temp;
		}
		temp = temp->end;
	}
	return (min);
}

t_dlist	*find_max(t_dlist **list)
{
	t_dlist	*temp;
	t_dlist	*max;
	int		i;

	temp = *list;
	max = *list;
	i = temp->number;
	while (temp)
	{
		if (i < temp->number)
		{
			i = temp->number;
			max = temp;
		}
		temp = temp->end;
	}
	return (max);
}
