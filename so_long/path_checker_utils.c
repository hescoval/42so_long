/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:57:10 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/14 06:29:32 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

char	**make_copy(char **src, int	height)
{
	int	i;
	char	**copy;
	
	copy = malloc(sizeof(char *) * (height + 1));
	i = 0;
	while (src[i])
	{
		copy[i] = ft_strdup(src[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

coins	*find_coins(char **input, int len, int height)
{
	static int	i;
	int			j;
	coins		*head;
	coins		*tail;
	coins		*new;

	head = NULL;
	while(i < height)
	{
		j = -1;
		while(++j < len)
		{
			if(input[i][j] == 'C')
			{
				new = make_coin(j, i);
				if(head == NULL)
					head = new;
				else
					tail->next = new;
				tail = new;
			}
		}
		i++;
	}
	return (head);
}

void	find_s_e(char **input, graphics *visuals)
{
	int	i;
	int	j;

	i = 0;
	while(input[i])
	{
		j = 0;
		while(input[i][j])
		{
			if(input[i][j] == 'P')
			{
				visuals->p_loc[0] = j;
				visuals->p_loc[1] = i;
			}
			if(input[i][j] == 'E')
			{
				visuals->e_loc[0] = j;
				visuals->e_loc[1] = i;
			}
			j++;
		}
		i++;
	}
}

coins	*make_coin(int x, int y)
{
	coins	*ret;

	ret = malloc(sizeof(coins));
	ret->x = x;
	ret->y = y;
	ret->next = NULL;
	return (ret);
}

int	check_coins(char **input, coins *head)
{
	int		bad;
	coins	*helper;

	bad = 0;
	while (head)
	{
		helper = head;
		if (input[head->y][head->x] != 'M')
			bad = 1;
		head = head->next;
		free(helper);
	}
	if (bad)
		return (0);
	return (1);
}