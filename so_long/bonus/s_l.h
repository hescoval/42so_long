/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_l.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:21:35 by hescoval          #+#    #+#             */
/*   Updated: 2024/02/03 12:53:42 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_L_H
# define S_L_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define MAX_LENGTH 60
# define MAX_HEIGHT 33
# define ENTITIES 8
# define I_L 32
# define I_H 32

typedef struct coins
{
	int				x;
	int				y;
	struct coins	*next;
}	t_coins;

typedef struct coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct graphics
{
	void	*mlx;
	void	*win;
	void	**imgs;
	char	**map;
	int		p_loc[2];
	int		e_loc[2];
	int		height;
	int		length;
	int		coins;
	int		moves;
}	t_graphics;

typedef enum KEYS
{
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100,
	LEFT_KP = 65361,
	UP_KP = 65362,
	RIGHT_KP = 65363,
	DOWN_KP = 65364,
	ESC = 65307
}	t_KEYS;

typedef enum MASKS
{
	WINDOW_CLOSE = 1L << 17,
	NO_MASK = 1L << 0
}	t_MASKS;

int		check_format(char *file);
int		valid_map(char *file, graphics *visuals);
int		p_error(char *str);
int		valid_path(graphics *visuals);
int		cleanup(graphics *visuals);

//	Map Checker Utils

int		custom_len(char *str);
int		all_ones(char *str);
int		check_walls(char *str, int len);
void	count_entities(char *str, int *e, int *s, int *c);
int		check_string(char *str);

//	Path Checker Utils

char	**make_copy(char **src, int arrays);
void	find_s_e(char **input, graphics *visuals);
coins	*make_coin(int x, int y);
coins	*find_coins(char **input, int len, int height);
int		check_coins(char **input, coins *head);

//	Graphical Stuff

void	start_game(graphics *visuals);
int		close_window(graphics *visuals);
int		key_press(int mask, graphics *visuals);
void	render_stuff(graphics *visuals, int i);
void	load_images(graphics *visuals);
void	refresh_image(graphics *visuals, int x, int y);
void	render_new_position(graphics *visuals);
void	render_old_position(graphics *visuals);

#endif