/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:05:53 by hescoval          #+#    #+#             */
/*   Updated: 2024/02/03 12:26:53 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

void	start_game(graphics *visuals)
{
	int	length;
	int	height;

	length = visuals->length * I_L;
	height = visuals->height * I_H;
	visuals->mlx = mlx_init();
	if (!visuals->mlx)
		cleanup(visuals);
	visuals->win = mlx_new_window(visuals->mlx, length, height, "new window");
	load_images(visuals);
	render_stuff(visuals, 0);
	visuals->map[visuals->p_loc[1]][visuals->p_loc[0]] = '0';
	mlx_hook(visuals->win, 2, NO_MASK, key_press, visuals);
	mlx_hook(visuals->win, 17, WINDOW_CLOSE, cleanup, visuals);
	mlx_loop(visuals->mlx);
}
