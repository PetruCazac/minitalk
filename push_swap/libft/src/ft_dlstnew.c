/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:55:12 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/08 10:06:17 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

t_dlist	*ft_dlstnew(int content)
{
	t_dlist	*tmp;

	tmp = malloc(sizeof(t_dlist));
	if (!tmp)
		return (NULL);
	if (tmp)
	{
		tmp->number = content;
		tmp->index = 0;
		tmp->next = NULL;
		tmp->previous = NULL;
	}
	return (tmp);
}
