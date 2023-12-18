/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:42:50 by nishi             #+#    #+#             */
/*   Updated: 2023/12/13 09:09:39 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

int main(int ac, char **av)
{
	if (ac != 2)
		return(p_error("Input"));
	if	(!check_format(av[1]))
		return (0);
	if	(!valid_map(av[1]))
		return (0);

	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	if(!mlx_ptr)
		return (1);

	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "new window");
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return 0;
}