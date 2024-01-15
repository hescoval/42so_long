/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:40:28 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/15 09:43:31 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

void    open_end(graphics *visuals)
{
    int end_x = visuals->e_loc[0] * 16;
    int end_y = visuals->e_loc[1] * 16;
    mlx_put_image_to_window(visuals->mlx, visuals->win, visuals->imgs[4], end_x, end_y);
}

void    refresh_image(graphics *visuals, int x, int y)
{
    if(visuals->map[y][x] == '1')
        return;
    visuals->moves++;
    ft_printf("Moves: %i\n", visuals->moves);
    if(visuals->map[y][x] == 'C')
        visuals->coins--;
    if(visuals->map[y][x] == 'H')
    {
        ft_printf("You lost!\n");
        cleanup(visuals);
    }
    if(visuals->map[y][x] == 'E')
    {
        if(visuals->coins == 0)
        {
            ft_printf("You won!\n");
            cleanup(visuals);
        }
    }
    render_old_position(visuals);
    visuals->p_loc[0] = x;
    visuals->p_loc[1] = y;
    render_new_position(visuals);
    if(visuals->coins == 0)
        open_end(visuals);
}

void    load_images(graphics *visuals)
{
    int size;

    size = 16;
    visuals->imgs = malloc(sizeof(void*) * ENTITIES);
    visuals->imgs[0] = mlx_xpm_file_to_image(visuals->mlx, "./images/wall.xpm", &size, &size);
    visuals->imgs[1] = mlx_xpm_file_to_image(visuals->mlx, "./images/player.xpm", &size, &size);
    visuals->imgs[2] = mlx_xpm_file_to_image(visuals->mlx, "./images/coin.xpm", &size, &size);
    visuals->imgs[3] = mlx_xpm_file_to_image(visuals->mlx, "./images/closed_door.xpm", &size, &size);
    visuals->imgs[4] = mlx_xpm_file_to_image(visuals->mlx, "./images/open_door.xpm", &size, &size);
    visuals->imgs[5] = mlx_xpm_file_to_image(visuals->mlx, "./images/blank.xpm", &size, &size);
    visuals->imgs[6] = mlx_xpm_file_to_image(visuals->mlx, "./images/EP.xpm", &size, &size);
    visuals->imgs[7] = mlx_xpm_file_to_image(visuals->mlx, "./images/cracked.xpm", &size, &size);
    visuals->imgs[8] = mlx_xpm_file_to_image(visuals->mlx, "./images/hole.xpm", &size, &size);
}

void    render_stuff(graphics *visuals)
{
    int i;
    int j;

    i = 0;
    while (i < visuals->height)
    {
        j = 0;
        while (j < visuals->length)
        {
            if (visuals->map[i][j] == '1')
                mlx_put_image_to_window(visuals->mlx, visuals->win, visuals->imgs[0], j * 16, i * 16);
            if (visuals->map[i][j] == 'P')
                mlx_put_image_to_window(visuals->mlx, visuals->win, visuals->imgs[1], j * 16, i * 16);
            if (visuals->map[i][j] == 'C')
                mlx_put_image_to_window(visuals->mlx, visuals->win, visuals->imgs[2], j * 16, i * 16);
            if (visuals->map[i][j] == 'E')
                mlx_put_image_to_window(visuals->mlx, visuals->win, visuals->imgs[3], j * 16, i * 16);
            if (visuals->map[i][j] == '0')
                mlx_put_image_to_window(visuals->mlx, visuals->win, visuals->imgs[7], j * 16, i * 16);
            j++;
        }
        i++;
    }
}