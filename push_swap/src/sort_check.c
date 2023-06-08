/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:04:06 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/06 17:17:29 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	sort_check(t_dlist **list)
{
	t_dlist	*temp;
	t_dlist	*temp2;
	int		i;

	i = 0;
	temp = *list;
	while (temp->next)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->number > temp2->number)
				return (0);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (1);
}

