/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_stuff_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 07:03:44 by hescoval          #+#    #+#             */
/*   Updated: 2024/02/03 12:37:52 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

void	render_old_position(t_graphics *visuals)
{
	int		old_x;
	int		old_y;
	char	**map;

	old_x = visuals->p_loc[0];
	old_y = visuals->p_loc[1];
	map = visuals->map;
	if (map[old_y][old_x] == '0')
		mlx_put_image_to_window(visuals->mlx, visuals->win, visuals->imgs[5],
			old_x * I_L, old_y * I_H);
	if (map[old_y][old_x] == 'E')
		mlx_put_image_to_window(visuals->mlx, visuals->win, visuals->imgs[3],
			old_x * I_L, old_y * I_H);
}

void	render_new_position(t_graphics *visuals)
{
	int		x;
	int		y;
	char	**map;

	x = visuals->p_loc[0];
	y = visuals->p_loc[1];
	map = visuals->map;
	if (map[y][x] == 'E')
		mlx_put_image_to_window(visuals->mlx, visuals->win, visuals->imgs[6], x
			* I_L, y * I_H);
	else
		mlx_put_image_to_window(visuals->mlx, visuals->win, visuals->imgs[1], x
			* I_L, y * I_H);
}
