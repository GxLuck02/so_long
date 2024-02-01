/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreichl <ttreichl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:14:15 by ttreichl          #+#    #+#             */
/*   Updated: 2024/02/01 15:02:07 by ttreichl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	init_window(t_game *game)
{
	game->mlx_pointer = mlx_init();
	if(is_larger_than_screen(game))// check size of screen and program
	{
		free_map(game);
		mlx_destroy_display(game->mlx_pointer);
		free(game->mlx_pointer);
		//endgame()
	}
	else
	{
		game->window_pointer = mlx_new_window(game->mlx_pointer, \
		(game->pole.length * SPRITE_SIZE), \
		(game->pole.height * SPRITE_SIZE), WINDOW_NAME);
	}
}

void	init_image(t_game *game)
{
	game->background = new_sprite(game->mlx_pointer, FLOOR_PATH);
	game->wall = new_sprite(game->mlx_pointer, WALL_PATH);
	game->collect = new_sprite(game->mlx_pointer, COLLECT_PATH);
	game->exit = new_sprite(game->mlx_pointer, EXIT_PATH);
	game->character = new_sprite(game->mlx_pointer, CHAR_PATH);
	game->character_l = new_sprite(game->mlx_pointer, CHAR_L_PATH);
	game->character_r = new_sprite(game->mlx_pointer, CHAR_R_PATH);
	game->character_u = new_sprite(game->mlx_pointer, CHAR_U_PATH);
	return ;
}

t_image	new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.length, &img.height);
	return (img);
}