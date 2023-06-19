/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:28:28 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/19 18:11:04 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"
#include <stdio.h>
void	ft_dlstclear(t_dlist **lst)
{
	t_dlist	*temp;
	int i = 0;
	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst)
	{
		temp = *lst;
		printf("%i\n",i++);
		// ft_printf("%i\n", temp->index);
		// (*lst)->prev = NULL;
		// (*lst)->next = NULL;
		// (*lst)->end = NULL;
		// (*lst)->pos = NULL;
		*lst = temp->end;
		free(temp);
	}
}
