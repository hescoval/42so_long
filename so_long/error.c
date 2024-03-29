/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:09:24 by hescoval          #+#    #+#             */
/*   Updated: 2024/02/03 12:52:59 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

int	p_error(char *str)
{
	if (ft_strcmp(str, "Line") == 0)
		ft_printf("Error\nNot enclosed or not uniform\n");
	if (ft_strcmp(str, "Rectangle") == 0)
		ft_printf("Error\nNot Rectangular\n");
	if (ft_strcmp(str, "Wall") == 0)
		ft_printf("Error\nNot Enclosed\n");
	if (ft_strcmp(str, "Entities") == 0)
		ft_printf("Error\nInvalid number of coins/starts/exits\n");
	if (ft_strcmp(str, "End") == 0)
		ft_printf("Error\nNo way to reach end\n");
	if (ft_strcmp(str, "File") == 0)
		ft_printf("Error\nFile Couldn't be opened\n");
	if (ft_strcmp(str, "Unknown") == 0)
		ft_printf("Error\nUnknown entity in map\n");
	if (ft_strcmp(str, "Input") == 0)
		ft_printf("Error\nArgument Count not correct (One only)\n");
	if (ft_strcmp(str, "Coins") == 0)
		ft_printf("Error\nNo way to reach all coins\n");
	if (ft_strcmp(str, "Map") == 0)
		ft_printf("Error\nMap size Invalid, Needs to be at most 60 x 33\n");
	return (0);
}
