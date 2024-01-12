/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_l.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:21:35 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/12 09:01:07 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_L
# define S_L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct coins
{
	int	x;
	int	y;
	struct coins *next;
}	coins;

typedef struct coords
{
	int	x;
	int	y;
}	coords;

typedef struct graphics
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	int		height;
	int		length;
	int		coins;
	int		moves;
}	graphics;

int 	check_format(char *file);
int		valid_map(char *file, graphics *visuals);
int		p_error(char *str);
int		valid_path(char **input, int height);
void	cleanup(graphics *visuals);

//	Map Checker Utils

int		custom_len(char *str);
int		all_ones(char *str);
int		check_walls(char *str, int len);
void	count_entities(char *str, int *e, int *s, int *c);
int		check_string(char *str);

//	Path Checker Utils

char	**make_copy(char **src, int	arrays);
void	find_s_e(char **input, coords *start, coords *end);
coins	*make_coin(int x, int y);
coins	*find_coins(char **input, int len, int height);
int		check_coins(char **input, coins *head);

//	Graphical Stuff

void    start_game(graphics *visuals);
int		close_window(int mask, void *visuals);

#endif