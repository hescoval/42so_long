/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:21:17 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/17 17:56:34 by hescoval         ###   ########.fr       */
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

int	valid_path(t_graphics *visuals)
{
	t_coins	*coin_head;
	char	**copy;

	find_s_e(visuals->map, visuals);
	copy = make_copy(visuals->map, visuals->height);
	coin_head = find_coins(copy, custom_len(copy[0]), visuals->height);
	flood_fill(copy, visuals->p_loc[0], visuals->p_loc[1]);
	if (!check_coins(copy, coin_head))
	{
		free_split(copy);
		return (p_error("Coins"));
	}
	if (copy[visuals->e_loc[1]][visuals->e_loc[0]] != 'M')
	{
		free_split(copy);
		return (p_error("End"));
	}
	free_split(copy);
	return (1);
}
