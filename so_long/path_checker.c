/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:21:17 by hescoval          #+#    #+#             */
/*   Updated: 2023/12/13 10:37:14 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"


void	flood_fill(char **input, int x, int y)
{
	if (input[y][x] == '1' || input[y][x] == 'M')
		return ;
	input[y][x] = 'M';
	flood_fill(input, x + 1, y);
	flood_fill(input, x - 1, y);
	flood_fill(input, x, y + 1);
	flood_fill(input, x, y - 1);
}

int	valid_path(char **input, int height)
{
	coords	start;
	coords	end;
	coins	*coin_head;

	find_s_e(input, &start, &end);
	char **copy = make_copy(input, height);
	coin_head = find_coins(copy, custom_len(copy[0]), height);
	flood_fill(copy, start.x, start.y);
	(void)coin_head;
	if (!check_coins(copy, coin_head))
	{
		free_split(copy);
		return(p_error("Coins"));
	}
	if (copy[end.y][end.x] != 'M')
	{
		free_split(copy);
		return(p_error("End"));
	}
	free_split(copy);
	return (1);
}
