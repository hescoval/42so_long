/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:42:50 by nishi             #+#    #+#             */
/*   Updated: 2024/01/12 09:28:04 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

int main(int ac, char **av)
{
	graphics *visuals;

	visuals = (graphics *)malloc(sizeof(graphics));
	if (ac != 2)
		return(p_error("Input"));
	if	(!check_format(av[1]))
		return (0);
	if	(!valid_map(av[1], visuals))
		return (0);
	
	start_game(visuals);
}