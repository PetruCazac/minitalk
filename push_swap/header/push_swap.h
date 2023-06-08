/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:01:15 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/07 15:51:10 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/header/libft.h"

int		check_input(int argc, char **argv, t_dlist **a);
void	rotate(t_dlist **stack, char st);
void	rrotate(t_dlist **stack, char st);
void	swap(t_dlist **stack, char st);
void	push(t_dlist **stack1, t_dlist **stack2, char st);
int		count_list(t_dlist **list_a);
void	sort_small(t_dlist **list_a);
t_dlist	*find_min(t_dlist **list);
t_dlist	*find_max(t_dlist **list);
int		sort_check(t_dlist **list);

#endif
