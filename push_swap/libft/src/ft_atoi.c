/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:38:55 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/03 10:24:16 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	transform(const char *s);
static int	ft_isspace(char str);

int	ft_atoi(const char *str)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
			j = transform(&str[i + 1]) * (-1);
	if (str[i] == '+')
			j = transform(&str[i + 1]);
	if (str[i] > 47 && str[i] < 58)
			j = transform(&str[i]);
	return (j);
}

static int	transform(const char *s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i] > 47 && s[i] < 58 && s[i])
	{
		j = j * 10 + (s[i] - 48);
		i++;
	}
	return (j);
}

static int	ft_isspace(char str)
{
	if (str == 32 || (str >= 9 && str <= 13))
		return (1);
	else
		return (0);
}
