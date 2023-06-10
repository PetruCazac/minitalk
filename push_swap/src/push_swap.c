/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:58:55 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/10 20:25:30 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Make the input check, see if the numbers are inputed as a string or as
// multiple arguments check if all the numbers are in a string or sepratly
// for each argument
#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;
	t_dlist	*temp;
	// int		i;

	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1])
		return (EXIT_FAILURE);
	if (check_input(argc, argv, &a) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	i = count_list(&a);
	if (i < 5)
		sort_small(&a);
	temp = a;
	while (temp)
	{
		ft_printf("-#%i#-\n", temp->number);
		temp = temp->next;
	}
	// if (i > 10)
	// 	sort_big(&a);
	if (sort_check(&a) == 0)
		ft_printf("Not sorted\n");
	else if (sort_check(&a) == 1)
		ft_printf("Sorted\n");
	return (EXIT_SUCCESS);
}

	// temp = a;
	// while (temp)
	// {
	// 	ft_printf("-#%i#-\n", temp->number);
	// 	temp = temp->end;
	// }
	// ft_printf("Nb. of elements: -#%i#-\n", count_list(&a));
	// ft_printf("Max element: -#%i#-\n", (find_max(&a))->number);
	// ft_printf("Min element: -#%i#-\n", (find_min(&a))->number);
	// rotate(&a, 'a');
	// temp = a;
	// while (temp)
	// {
	// 	ft_printf("Rotated -#%i#-\n", temp->number);
	// 	temp = temp->end;
	// }
	// rrotate(&a, 'a');
	// temp = a;
	// while (temp)
	// {
	// 	ft_printf("Inverse Rotated -#%i#-\n", temp->number);
	// 	temp = temp->end;
	// }
	// swap(&a, 'a');
	// temp = a;
	// while (temp)
	// {
	// 	ft_printf("Swap -#%i#-\n", temp->number);
	// 	temp = temp->end;
	// }
	// swap(&a, 'a');
	// temp = a;
	// while (temp)
	// {
	// 	ft_printf("Swap back -#%i#-\n", temp->number);
	// 	temp = temp->end;
	// }
	// push(&a, &b, 'b');
	// temp = a;
	// while (temp)
	// {
	// 	ft_printf("Push a-#%i#-\n", temp->number);
	// 	temp = temp->end;
	// }
	// 	while (b)
	// {
	// 	ft_printf("Push b-#%i#-\n", b->number);
	// 	b = b->end;
	// }
	// Allocate the numbers to a linked list
	// make_list(argc, argv, a);
	// Presort the numbers and add an index to each of them
	// presort(a);
	// Send the list to a sorting algorithm that will sort the numbers
	// and print the actions everytime
	// sort_algorithm(a);



// make_list is a function that has to take the arguments and create a 
// node in a linked list for each of them, copy the value of the number and
// set the index for each of them 0. This function has to allocate memory
// space for the numbers.

// presort is a function that has to sort the numbers using a rapid sorting
// algorithm and assign to these nodes an index of the sorted order
// The function has to copy the linked list into a new one, sort it and
// copy the index from the sorted linkd list to the initial unsorted one

// sort_algorithm must take into account only the index numbers and operate
// only with these numbers. It should have a sorting part that will sort a small
// ammount of numbers ~3 and use an algorithm that will calculate how many
// moves it takes to sort each number each time a number is moved to it's place
// and it will choose the option with the least ammount of moves. It should
// also have in each node a validation check if the number is sorted/ or it 
// should have a sorting checker and check each time if the list is sorted and
// finish the sorting. Each time a number is sorted it should print the sorting
// orders.

// Additional functions should be written to help with the linked lists handling
// and the checking.