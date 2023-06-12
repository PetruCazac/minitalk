// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   push_swap_quiet.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/06/12 12:02:28 by pcazac            #+#    #+#             */
// /*   Updated: 2023/06/12 18:59:57 by pcazac           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../header/push_swap.h"

// void	rotateq(t_dlist **stack)
// {
// 	t_dlist	*head;
// 	t_dlist	*tail;

// 	head = *stack;
// 	tail = head->previous;
// 	*stack = head->next;
// 	head->end = NULL;
// 	tail->end = head;
// 	return ;
// }

// void	rrotateq(t_dlist **stack)
// {
// 	t_dlist	*head;
// 	t_dlist	*tail;

// 	if ((*stack)->end == NULL)
// 		return ;
// 	head = *stack;
// 	tail = head->previous;
// 	*stack = tail;
// 	tail->previous->end = NULL;
// 	tail->end = head;
// 	return ;
// }

// void	push_to_non_emptyq(t_dlist **stack1, t_dlist **stack2)
// {
// 	t_dlist	*temp1;
// 	t_dlist	*temp2;
// 	static int	i = 0;

// 	temp1 = *stack1;
// 	temp2 = *stack2;
// 	*stack1 = temp1->next;
// 	temp1->next->previous = temp1->previous;
// 	temp1->previous->next = temp1->next;
// 	*stack2 = temp1;
// 	temp1->next = temp2;
// 	temp1->end = temp2;
// 	if (temp2->previous)
// 		temp1->previous = temp2->previous;
// 	else
// 		temp1->previous = temp2;
// 	temp1->previous->next = temp1;
// 	temp2->previous = temp1;
// 	i++;
// 	return ;
// }

// void	pushq(t_dlist **stack1, t_dlist **stack2)
// {
// 	t_dlist	*temp1;

// 	if (!(*stack1))
// 		return ;
// 	if (!(*stack2))
// 	{
// 		temp1 = *stack1;
// 		*stack1 = temp1->next;
// 		temp1->next->previous = temp1->previous;
// 		temp1->previous->next = temp1->next;
// 		*stack2 = temp1;
// 		temp1->previous = NULL;
// 		temp1->next = NULL;
// 		temp1->end = NULL;
// 		return ;
// 	}
// 	else if (*stack2 != NULL)
// 		push_to_non_emptyq(stack1, stack2);
// 	return ;
// }

// void	swapq(t_dlist **stack)
// {
// 	t_dlist	*temp;
// 	t_dlist	*head;

// 	head = *stack;
// 	temp = head->next;
// 	*stack = temp;
// 	temp->previous = head->previous;
// 	temp->previous->next = temp;
// 	head->previous = temp;
// 	head->end = temp->end;
// 	temp->end = head;
// 	head->next = temp->next;
// 	temp->next = head;
// 	head->next->previous = head;
// 	return ;
// }
