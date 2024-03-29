/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:21:24 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/17 18:04:16 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

int	get_last(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i - 1);
}

int	check_format(char *file)
{
	char	**testing;
	int		i;

	if (ft_strchr(file, '.') == NULL)
	{
		ft_printf("Error\nNo file extension\n");
		return (0);
	}
	testing = ft_split(file, '.');
	if (!testing)
		return (0);
	i = get_last(testing);
	if (ft_strcmp(testing[i], "ber") != 0)
	{
		ft_printf("Error\nFile is wrong format\n");
		free_split(testing);
		return (0);
	}
	free_split(testing);
	return (1);
}
