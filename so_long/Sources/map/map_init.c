/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreichl <ttreichl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:31:13 by ttreichl          #+#    #+#             */
/*   Updated: 2024/02/01 15:05:28 by ttreichl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void    init_map(t_game *game, char *path)
{
	int     fd;

	fd = open_file(path);
	read_map(game, fd);
	game->pole.length = is_valid_length(game);// permet de vérifier que chaque ligne a la meme taille
	check_surrounded_wall(game);
	close(fd);
	return ;
}

void    read_map(t_game *game, int fd)
{
	char   *tmp;

	tmp = ft_strdup("");
	game->pole.height = 0;
	while (fd)// Permet de créé un seul ligne avec le fichier .ber (map) et calcule la hauteur de la map
	{
		game->pole.line = get_next_line(fd); //si leak verifier
		if (game->pole.line == NULL)
			break ;
		tmp = ft_strjoin(tmp, game->pole.line);
		free(game->pole.line);
		game->pole.height++;
	}
	game->count_element = start_counter(tmp);
	game->pole.map = ft_split(tmp, '\n');
	return ;
}

t_counter    start_counter(char *string_map)
{
	t_counter	cne; //count nbr element
	int			i;

	i = 0;
	cne = new_counter();
	while (string_map[i] != '\0')
	{
		count_element(&cne, string_map[i]);
		i++;
	}
	is_element_nbr_valid(&cne, string_map); 
	return (cne);
}

void	check_surrounded_wall(t_game *game)
{
	int x;
	int y;

	x = 0;
	while (game->pole.map[0][x++] != '\0')
	{
		if (game->pole.map[0][x] != 1)
			return;//endgame("pas entourer de mur")********************************************************************
	}
	y = 1;
	while (y++ < (game->pole.height - 1))
	{
		if (game->pole.map[y][0] != 1)
			return ;//endgame("pas entourer de mur")********************************************************************
		if (game->pole.map[y][game->pole.length - 1] != 1)
			return;//endgame("pas entourer de mur")********************************************************************
	}
	x = 0;
	while (game->pole.map[game->pole.height - 1][x++] != '\0')
	{
		if (game->pole.map[game->pole.height - 1][x] != 1)
			return;//endgame("pas entourer de mur")********************************************************************
	}
	return ;
}

void	build_floor(t_game *game)
{
	int     x;
	int     y;

	y = 0;
	while (y++ < game->pole.height)
	{
		x = 0;
		while (x++ <  game->pole.length)
		{
			mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->background.ptr, x * SPRITE_SIZE, y * SPRITE_SIZE);
		}
	}
	return ;
}