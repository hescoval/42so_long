/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:07:16 by hescoval          #+#    #+#             */
/*   Updated: 2024/02/03 12:36:31 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

size_t	count_lines(char *file)
{
	int		fd;
	char	*str;
	size_t	line_count;

	line_count = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		line_count++;
		str = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

char	**parse_input(char *file, int height)
{
	int		fd;
	char	**lines;
	char	*str;
	int		i;

	i = 0;
	lines = malloc(sizeof(char *) * (height + 1));
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(lines);
		return (NULL);
	}
	str = get_next_line(fd);
	while (str)
	{
		lines[i++] = str;
		str = get_next_line(fd);
	}
	lines[i] = NULL;
	close(fd);
	return (lines);
}

int	check_ents(char **input, t_graphics *visuals)
{
	static int	i;
	static int	exits;
	static int	starts;
	static int	collectibles;

	if (visuals->length == visuals->height)
		return (p_error("Rectangle"));
	if (!all_ones(input[0]) || !all_ones(input[visuals->height - 1]))
		return (p_error("Wall"));
	while (input[i])
	{
		if (!check_walls(input[i], visuals->length)
			|| custom_len(input[i]) != visuals->length)
			return (p_error("Line"));
		count_entities(input[i], &exits, &starts, &collectibles);
		if (!check_string(input[i]))
			return (p_error("Unknown"));
		i++;
	}
	if (exits != 1 || starts != 1 || collectibles < 1)
		return (p_error("Entities"));
	ft_printf("Found %i Coin(s), %i start(s) and %i exit(s)\n", collectibles,
		starts, exits);
	visuals->coins = collectibles;
	return (1);
}

int	valid_map(char *file, t_graphics *visuals)
{
	int	bad;

	bad = 0;
	visuals->height = count_lines(file);
	visuals->map = parse_input(file, visuals->height);
	if (!visuals->map)
		return (p_error("File"));
	visuals->length = custom_len(visuals->map[0]);
	if (!check_ents(visuals->map, visuals))
		bad = 1;
	printf("height: %i, length: %i\n", visuals->height, visuals->length);
	if (visuals->height > MAX_HEIGHT || visuals->length > MAX_LENGTH)
		return (p_error("Map"));
	if (!valid_path(visuals))
		bad = 1;
	if (bad)
		return (0);
	return (1);
}
