/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreichl <ttreichl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:36:33 by ttreichl          #+#    #+#             */
/*   Updated: 2024/01/31 14:39:00 by ttreichl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H

# define SPRITE_SIZE	50
# define WINDOW_NAME	"./so_long"

# define UP		119
# define DOWN	115
# define LEFT	97
# define RIGHT	100
# define ESC	65307

# define KEY_RELEASE	3
# define KEY_PRESS		2

enum e_direction
{
	down,
	left,
	right,
	up,
};

typedef struct s_counter
{
	int		empty;
	int		collectible;
	int		exit;
	int		start;
	int		movements;
}	            t_counter;

typedef	struct s_plot
{
	char	**map;
	int		height;
	int		length;
	char	*line;
}				t_map;

typedef	struct s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct s_image
{
	void	*ptr;
	char	*data;
	int		line_size;
	int		mem;
	int		length;
	int		height;
	int		endian;
}				t_image;

typedef struct s_game
{
	void		*mlx_pointer;
	void		*window_pointer;
	t_counter	count_element;
	t_map		pole;
	t_image		background;//floor
	t_image		wall;
	t_image		collect;
	t_image		exit;
	t_image		character;
	t_image		character_l;
	t_image		character_r;
	t_image		character_u;
}               t_game;

#endif