/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:03:49 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/14 06:34:54 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

int key_press(int key, graphics *visuals)
{
    if(key == ESC)
        cleanup(visuals);
    if(key == UP_KP || key == W_KEY)
        refresh_image(visuals, visuals->p_loc[0], visuals->p_loc[1] - 1);
    if(key == DOWN_KP || key == S_KEY)
        refresh_image(visuals, visuals->p_loc[0], visuals->p_loc[1] + 1);
    if(key == LEFT_KP || key == A_KEY)
        refresh_image(visuals, visuals->p_loc[0] - 1, visuals->p_loc[1]);
    if(key == RIGHT_KP || key == D_KEY)
        refresh_image(visuals, visuals->p_loc[0] + 1, visuals->p_loc[1]);
    return(0);
}

int cleanup(graphics *visuals)
{
    int i;
    
    i = 0;
    if (visuals->win)
        mlx_destroy_window(visuals->mlx, visuals->win);
    if (visuals->mlx)
    {
        while(i < ENTITIES)
            if (visuals->imgs[i])
                mlx_destroy_image(visuals->mlx, visuals->imgs[i++]);
        if(visuals->imgs)
                free(visuals->imgs);
        mlx_destroy_display(visuals->mlx);
        free(visuals->mlx);
    }
    if (visuals->map)
        free_split(visuals->map);
    if (visuals)
        free(visuals);
    exit(1);
    return(0);
}
