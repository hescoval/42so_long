/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:12:07 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/17 17:45:43 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compare(char *find, char *search, size_t index, size_t len)
{
	size_t	j;

	j = 0;
	while (find[j])
	{
		if (find[j] != search[index + j])
			return (0);
		j ++;
	}
	if (index + j > len)
		return (0);
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*helper;

	helper = (char *) big;
	i = 0;
	if (little[0] == '\0')
		return (helper);
	while (big[i] && i < len)
	{
		if (big[i] == little[0] && compare((char *)little, (char *)big, i, len))
		{
			return (helper);
		}
		i ++;
		helper ++;
	}
	return (NULL);
}
