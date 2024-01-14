/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:42:50 by nishi             #+#    #+#             */
/*   Updated: 2024/01/14 07:00:38 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

int main(int ac, char **av)
{
	graphics *visuals;

	if (ac != 2)
		return(p_error("Input"));
	if	(!check_format(av[1]))
		return (0);
	visuals = (graphics *)malloc(sizeof(graphics));
	ft_bzero(visuals, sizeof(graphics));
	if	(!valid_map(av[1], visuals))
	{
		cleanup(visuals);
		return (0);
	}
	start_game(visuals);
}