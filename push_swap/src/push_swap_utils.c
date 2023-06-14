/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:19:38 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/14 10:28:11 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
// The first element goes at the bottom
void	rotate(t_dlist **stack, char st)
{
	t_dlist	*head;
	t_dlist	*tail;

	head = *stack;
	tail = head->prev;
	*stack = head->next;
	head->end = NULL;
	tail->end = head;
	ft_printf("r%c\n", st);
	return ;
}

void	rotate_both(t_dlist **a, t_dlist **b)
{
	t_dlist	*head;
	t_dlist	*tail;
// Rotate stack a
	head = *a;
	tail = head->prev;
	*a = head->next;
	head->end = NULL;
	tail->end = head;
// Rotate stack b
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
// Rotate stack a
	if ((*a)->end == NULL)
		return ;
	head = *a;
	tail = head->prev;
	*a = tail;
	tail->prev->end = NULL;
	tail->end = head;
// Rotate stack b
	if ((*b)->end == NULL)
		return ;
	head = *b;
	tail = head->prev;
	*b = tail;
	tail->prev->end = NULL;
	tail->end = head;
	ft_printf("rrr\n");
}

// The last element goes at the top
void	rrotate(t_dlist **stack, char st)
{
	t_dlist	*head;
	t_dlist	*tail;

	if ((*stack)->end == NULL)
		return ;
	head = *stack;
	tail = head->prev;
	*stack = tail;
	tail->prev->end = NULL;
	tail->end = head;
	ft_printf("rr%c\n", st);
	return ;
}

void	push_to_non_empty(t_dlist **stack1, t_dlist **stack2, char st)
{
	t_dlist	*temp1;
	t_dlist	*temp2;

	temp1 = *stack1;
	temp2 = *stack2;
	*stack1 = temp1->end;
	temp1->next->prev = temp1->prev;
	temp1->prev->next = temp1->next;
	*stack2 = temp1;
	temp1->next = temp2;
	temp1->end = temp2;
	if (temp2->prev)
		temp1->prev = temp2->prev;
	else
		temp1->prev = temp2;
	temp1->prev->next = temp1;
	temp2->prev = temp1;
	ft_printf("p%c\n", st);
	return ;
}
// Push from stack 1 to stack 2
void	push(t_dlist **stack1, t_dlist **stack2, char st)
{
	t_dlist	*temp1;

	if (!(*stack1))
		return ;
	if (!(*stack2))
	{
		temp1 = *stack1;
		*stack1 = temp1->next;
		temp1->next->prev = temp1->prev;
		temp1->prev->next = temp1->next;
		*stack2 = temp1;
		temp1->prev = NULL;
		temp1->next = NULL;
		temp1->end = NULL;
		ft_printf("p%c\n", st);
		return ;
	}
	else if (*stack2)
		push_to_non_empty(stack1, stack2, st);
	return ;
}
// Swap the first 2 elements
void	swap(t_dlist **stack, char st)
{
	t_dlist	*temp;
	t_dlist	*head;

	head = *stack;
	temp = head->next;
	*stack = temp;
	temp->prev = head->prev;
	temp->prev->next = temp;
	head->prev = temp;
	head->end = temp->end;
	temp->end = head;
	head->next = temp->next;
	temp->next = head;
	head->next->prev = head;
	ft_printf("s%c\n", st);
	return ;
}
