/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:00:29 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/11 16:16:22 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		new->end = NULL;
		return ;
	}
	temp = *lst;
	while (temp->end != NULL)
		temp = temp->end;
	temp->next = new;
	temp->end = new;
	new->previous = temp;
	new->end = NULL;
	(*lst)->previous = new;
	new->next = (*lst);
}
