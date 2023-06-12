/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:04:06 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/11 19:28:41 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	sort_check(t_dlist **list)
{
	t_dlist	*temp;
	t_dlist	*temp2;

	temp = *list;
	while (temp->end)
	{
		temp2 = temp->end;
		while (temp2)
		{
			if (temp->number > temp2->number)
				return (0);
			temp2 = temp2->end;
		}
		temp = temp->end;
	}
	return (1);
}

