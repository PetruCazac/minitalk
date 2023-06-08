/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:27:24 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/08 14:15:38 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_dlist	*copy_list(t_dlist **a)
{
	t_dlist	*b;
	t_dlist	*temp;

	temp = (*a);
	while (temp->next)
	{
		ft_dlstadd_back(b, ft_dlstnew(temp->number));
		temp = temp->next;
	}
	return (b);
}

void	presort(t_dlist **a)
{
	t_dlist	*b;

	b = copy_list(a);
	
}