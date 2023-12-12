/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:07:16 by hescoval          #+#    #+#             */
/*   Updated: 2023/12/12 18:34:40 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

size_t	count_lines(char *file)
{
	int		fd;
	char	*str;
	size_t		line_count;

	line_count = 0;
	fd = open(file, O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		free(str);
		line_count++;
	}

	close(fd);
	return (line_count);
}

char	**parse_input(char *file, int *height)
{
	int		fd;
	char	**lines;
	char	*str;
	int		i;

	i = 0;
	*height = count_lines(file);
	lines = malloc(sizeof(char *) * (*height + 1));
	fd = open(file, O_RDONLY);
	if(fd == -1)
	{
		free(lines);
		return(NULL);
	}
	while ((str = get_next_line(fd)))
		lines[i++] = str;
	lines[i] = NULL;

	close(fd);
	return (lines);
}
int	check_ents(char **input, int height, int length)
{
	static int	i;
 	static int	exits;
	static int	starts;
	static int	collectibles;

	if (length == height)
		return(p_error("Rectangle"));
	if (!all_ones(input[0]) || !all_ones(input[height - 1]))
		return(p_error("Wall"));
	while (input[i])
	{
		if(!check_walls(input[i], length) || custom_len(input[i]) != length)
			return(p_error("Line"));
		count_entities(input[i], &exits, &starts, &collectibles);
		i++;
	}
	if(exits != 1 || starts != 1 || collectibles < 1)
		return (p_error("Entities"));
	printf("Found %i Coins, %i starts and %i exits", collectibles, starts, exits);
	return (1);
}

int valid_map(char *file)
{
	char	**input;
	int		height;
	int		length;

	input = parse_input(file, &height);
	if(!input)
		return(p_error("File"));
	length = custom_len(input[0]);

	if (!check_ents(input, height, length))
	{
		free_split(input);
		return 0;
	}
	
	free_split(input);
	return 1;
}
