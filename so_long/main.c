/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:42:50 by nishi             #+#    #+#             */
/*   Updated: 2023/12/12 16:06:10 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error\no input file, or too many arguments");
		return 0;
	}
	if	(!check_format(av[1]))
		return 0;
	if	(!valid_map(av[1]))
		return 0;
}