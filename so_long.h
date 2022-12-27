/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 05:00:02 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/21 03:06:12 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "./libft/libft.h"
# include "./printf/libftprintf.h"
# include "./minilibx/mlx.h"

typedef struct s_point{
	int	x;
	int	y;
}				t_point;

typedef struct s_image{
	void	*image;
	t_point	dims;
	char	*pixels;
	int		*bits_per_pixel;
	int		endian;
}				t_image;

typedef struct s_map{
	void	*world_map;
	char	**map;
	t_point	dims;
}				t_map;

typedef struct s_player{
	t_image	player;
	t_point	pos;
}				t_player;

typedef struct s_game_master{
	void		*world_seed;
	t_map		map;
	t_point		world_bounds;
	t_player	player;
	int			moves;
	int			finished;
	int			frames;
	int			cs;
}				t_game_master;

static t_game_master	g_master;

int				key_press(int key, void *params);
int				locator(char **map, char character);
int				wall_condition(t_game_master gm);
int				name_condition(char *name);
int				conditions_met(t_game_master gm);
void			display_map(char **map);
int				content_locator(char **map);
void			ft_error(char *error_message, t_game_master *gm);
t_game_master	map_dims(t_game_master gm);
int				ft_close(void);
void			display_numbers(t_game_master *gm);
void			game_won(t_game_master *gm, int frame);
void			ft_free_map(t_game_master *gm);
int				check_mate(t_game_master *gm, int *i, int *j, t_point *pos);
int				game_stop(t_game_master *gm);
void			move_locator(t_game_master *gm, t_point *pos, int *x, int *y);
void			*fotographer(t_game_master *gm, char *picture, int x, int y);
t_game_master	setup_player(t_game_master gm);
void			init_loss(t_game_master *gm, int frame, int x, int y);
void			checker(t_game_master *gm, char *name);
int				line_reader(int fd, t_game_master *gm);
void			patrol(t_game_master *gm, int frame);

#endif
