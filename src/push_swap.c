/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:58:55 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/19 18:15:52 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
		ft_dlstclear(&a);
		return (EXIT_FAILURE);
	}
	if (sort_check(&a))
	{
		ft_dlstclear(&a);
		return (EXIT_SUCCESS);
	}
	presort(&a, &b);
	if (count_list(&a) <= 5)
	{
		sort_small(&a, &b, &element);
		ft_dlstclear(&a);
		return (EXIT_SUCCESS);
	}
	push_b(&a, &b, &element);
	ft_dlstclear(&a);
	return (EXIT_SUCCESS);
}
