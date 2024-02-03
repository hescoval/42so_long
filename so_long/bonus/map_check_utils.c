/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:07:39 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/17 18:07:38 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

int	custom_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	all_ones(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char *str, int len)
{
	if (str[0] != '1' || str[len - 1] != '1')
		return (0);
	return (1);
}

void	count_entities(char *str, int *e, int *s, int *c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'E')
			*e += 1;
		if (str[i] == 'C')
			*c += 1;
		if (str[i] == 'P')
			*s += 1;
		i++;
	}
}

int	check_string(char *str)
{
	int		i;
	char	*valid;
	int		j;
	int		found;

	valid = "PEC10\n";
	i = 0;
	while (str[i])
	{
		j = 0;
		found = 0;
		while (valid[j])
		{
			if (str[i] == valid[j])
				found = 1;
			j++;
		}
		if (!found)
			return (0);
		i++;
	}
	return (1);
}
