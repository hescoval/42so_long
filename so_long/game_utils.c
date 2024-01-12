/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:05:53 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/12 09:34:35 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

void    start_game(graphics *visuals)
{
    visuals->mlx = mlx_init();
	if (!visuals->mlx)
        cleanup(visuals);
	visuals->win = mlx_new_window(visuals->mlx, 640, 480, "new window");
    if  (!visuals->win)
        cleanup(visuals);
    
    mlx_hook(visuals->win, 17, (1L << 17), close_window, visuals); // why does this seg fault?
    mlx_loop(visuals->mlx);
}