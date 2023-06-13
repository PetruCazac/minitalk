/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:58:55 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/13 08:41:24 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;
	// int		count;
	// t_dlist	*temp;
	
	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1])
		return (EXIT_FAILURE);
	if (check_input(argc, argv, &a) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	if (sort_check(&a))
		return (EXIT_SUCCESS);
	presort(&a, &b);
	push_b(&a, &b);
	// temp = b;
	// count = 0;
	// while (temp)
	// {
	// 	ft_printf("b : %i\n", temp->number);
	// 	count++;
	// 	temp = temp->end;
	// }
	// ft_printf("count b : %i\n", count);
	// count = 0;
	// temp = a;
	// while (temp)
	// {
	// 	ft_printf("a : %i\n", temp->number);
	// 	count++;
	// 	temp = temp->end;
	// }
	// ft_printf("count a: %i\n", count);
	// sort_back(&a, &b);
	return (EXIT_SUCCESS);
}


	// i = count_list(&a);
	// if (i < 5)
	// 	sort_small(&a);
	// if (i > 10)
	// 	sort_big(&a);
	// if (sort_check(&a) == 0)
	// 	ft_printf("Not sorted\n");
	// else if (sort_check(&a) == 1)
	// 	ft_printf("Sorted\n");

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
