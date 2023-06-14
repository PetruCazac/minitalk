/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:53:02 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/14 11:54:22 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	check_int(char *a)
{
	int	j;

	j = 0;
	if (a[j] != '+' && a[j] != '-' && !ft_isdigit(a[j]))
		return (0);
	if (a[j] == '+' || a[j] == '-')
		j++;
	while (a[j])
	{
		if (!ft_isdigit(a[j]))
			return (0);
		j++;
	}
	return (j);
}

int	check_duplicates(t_dlist **a, int i)
{
	t_dlist	*a_temp;

	a_temp = *a;
	while (a_temp)
	{
		if (a_temp->number == i)
			return (0);
		a_temp = a_temp->end;
	}
	return (1);
}

int	make_list(char **arr, t_dlist **a)
{
	int		i;
	t_dlist	*temp;

	i = 0;
	while (arr[i])
	{
		if (check_int(arr[i]) == 0)
			return (0);
		temp = ft_dlstnew(ft_atoi(arr[i]));
		if (temp == (void *)0)
			return (0);
		if (check_duplicates(a, temp->number) == 0)
			return (free(temp), 0);
		ft_dlstadd_back(a, temp);
		i++;
	}
	return (1);
}

int	check_input(int argc, char **argv, t_dlist **a)
{
	int		i;
	char	**arr;
	int		j;

	i = 0;
	while (++i < argc)
	{
		arr = ft_split(argv[i], ' ');
		if (!arr[0])
			return (0);
		if (make_list(arr, a) == 0)
			return (ft_dlstclear(a), 0);
		j = -1;
		while (arr[++j])
			free(arr[j]);
		free(arr);
	}
	return (1);
}
