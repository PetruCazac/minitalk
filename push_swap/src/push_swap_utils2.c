/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:19:38 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/19 13:56:02 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rotate_both(t_dlist **a, t_dlist **b)
{
	t_dlist	*head;
	t_dlist	*tail;

	if ((*a)->end == NULL)
		return ;
	head = *a;
	tail = head->prev;
	*a = head->next;
	head->end = NULL;
	tail->end = head;
	head = *b;
	tail = head->prev;
	*b = head->next;
	head->end = NULL;
	tail->end = head;
	ft_printf("rr\n");
}

void	rrotate_both(t_dlist **a, t_dlist **b)
{
	t_dlist	*head;
	t_dlist	*tail;

	if ((*a)->end == NULL)
		return ;
	if ((*b)->end == NULL)
		return ;
	head = *a;
	tail = head->prev;
	*a = tail;
	tail->prev->end = NULL;
	tail->end = head;
	head = *b;
	tail = head->prev;
	*b = tail;
	tail->prev->end = NULL;
	tail->end = head;
	ft_printf("rrr\n");
}
