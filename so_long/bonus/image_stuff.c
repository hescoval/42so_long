/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:40:28 by hescoval          #+#    #+#             */
/*   Updated: 2024/02/03 12:28:00 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

void	open_end(t_graphics *v)
{
	int	end_x;
	int	end_y;

	end_x = v->e_loc[0] * I_L;
	end_y = v->e_loc[1] * I_H;
	mlx_put_image_to_window(v->mlx, v->win, v->imgs[4], end_x,
		end_y);
}

void	refresh_image(t_graphics *v, int x, int y)
{
	if (v->map[y][x] == '1')
		return ;
	v->moves++;
	ft_printf("Moves: %i\n", v->moves);
	if (v->map[y][x] == 'C')
		v->coins--;
	if (v->map[y][x] == 'H')
	{
		ft_printf("You lost!\n");
		cleanup(v);
	}
	if (v->map[y][x] == 'E')
	{
		if (v->coins == 0)
		{
			ft_printf("You won!\n");
			cleanup(v);
		}
	}
	render_old_position(v);
	v->p_loc[0] = x;
	v->p_loc[1] = y;
	render_new_position(v);
	if (v->coins == 0)
		open_end(v);
}

void	load_images(t_graphics *v)
{
	int	size;

	size = 32;
	v->imgs = malloc(sizeof(void *) * ENTITIES);
	v->imgs[0] = mlx_xpm_file_to_image(v->mlx, "./images/wall.xpm",
			&size, &size);
	v->imgs[1] = mlx_xpm_file_to_image(v->mlx,
			"./images/player.xpm", &size, &size);
	v->imgs[2] = mlx_xpm_file_to_image(v->mlx, "./images/coin.xpm",
			&size, &size);
	v->imgs[3] = mlx_xpm_file_to_image(v->mlx,
			"./images/closed_door.xpm", &size, &size);
	v->imgs[4] = mlx_xpm_file_to_image(v->mlx,
			"./images/open_door.xpm", &size, &size);
	v->imgs[5] = mlx_xpm_file_to_image(v->mlx, "./images/blank.xpm",
			&size, &size);
	v->imgs[6] = mlx_xpm_file_to_image(v->mlx, "./images/EP.xpm",
			&size, &size);
	v->imgs[7] = mlx_xpm_file_to_image(v->mlx, "./images/X.xpm",
			&size, &size);
}

void	render_stuff(t_graphics *v, int i)
{
	int	j;
	int	w;
	int	h;

	while (++i < v->height)
	{
		j = 0;
		while (j < v->length)
		{
			w = j * I_L;
			h = i * I_H;
			if (v->map[i][j] == '1')
				mlx_put_image_to_window(v->mlx, v->win, v->imgs[0], w, h);
			if (v->map[i][j] == 'P')
				mlx_put_image_to_window(v->mlx, v->win, v->imgs[1], w, h);
			if (v->map[i][j] == 'C')
				mlx_put_image_to_window(v->mlx, v->win, v->imgs[2], w, h);
			if (v->map[i][j] == 'E')
				mlx_put_image_to_window(v->mlx, v->win, v->imgs[3], w, h);
			if (v->map[i][j] == '0')
				mlx_put_image_to_window(v->mlx, v->win, v->imgs[5], w, h);
			j++;
		}
	}
}
