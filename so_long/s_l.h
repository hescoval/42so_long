#ifndef S_L
# define S_L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct coords
{
	int	x;
	int	y;
}	coords;

int check_format(char *file);
int valid_map(char *file);
int	all_ones(char *str);
int	check_walls(char *str, int len);
void	count_entities(char *str, int *e, int *s, int *c);
int	custom_len(char *str);
int	p_error(char *str);

#endif