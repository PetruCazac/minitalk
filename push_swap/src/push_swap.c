/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:58:55 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/13 15:10:09 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;
	t_dlist	*element;
	
	a = NULL;
	b = NULL;
	element = NULL;
	if (argc < 2 || !argv[1])
		return (EXIT_FAILURE);
	if (check_input(argc, argv, &a) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	if (sort_check(&a))
		return (EXIT_SUCCESS);
	if (count_list(&a) <= 3)
	{
		sort_small(&a);
		return (EXIT_SUCCESS);
	}
	presort(&a, &b);
	push_b(&a, &b, &element);
	return (EXIT_SUCCESS);
}
