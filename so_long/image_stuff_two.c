/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_stuff_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 07:03:44 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/14 07:09:56 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

void    render_old_position(graphics *visuals)
{
    int old_x = visuals->p_loc[0];
    int old_y = visuals->p_loc[1];
    char    **map = visuals->map;
    if(map[old_y][old_x] == '0')
        mlx_put_image_to_window(visuals->mlx, visuals->win, visuals->imgs[5], old_x * 16, old_y * 16);
    if(map[old_y][old_x] == 'E')
        mlx_put_image_to_window(visuals->mlx, visuals->win, visuals->imgs[3], old_x * 16, old_y * 16);
    
}

void    render_new_position(graphics *visuals)
{
    int x = visuals->p_loc[0];
    int y = visuals->p_loc[1];
    char    **map = visuals->map;
    
    if(map[y][x] == 'E')
        mlx_put_image_to_window(visuals->mlx, visuals->win, visuals->imgs[3], x * 16, y * 16);
    mlx_put_image_to_window(visuals->mlx, visuals->win, visuals->imgs[1], x * 16, y * 16);
}