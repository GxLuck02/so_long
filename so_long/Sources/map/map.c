/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreichl <ttreichl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:28:37 by ttreichl          #+#    #+#             */
/*   Updated: 2024/01/31 15:42:52 by ttreichl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void    map_maker(t_game *game, int y, int x)
{
    if (game->pole.map[y][x] == 'E')
    {
        game->exit.length = x * SPRITE_SIZE;
        game->exit.height = y * SPRITE_SIZE;
        mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->exit.ptr, x * SPRITE_SIZE, y * SPRITE_SIZE);
    }
    else if (game->pole.map[y][x] == '1')
        mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->wall.ptr, x * SPRITE_SIZE, y * SPRITE_SIZE);
    else if (game->pole.map[y][x] == 'C')
        mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->collect.ptr, x * SPRITE_SIZE, y * SPRITE_SIZE);
    else
        return ;
}

void    render_map(t_game *game)
{
    t_point coord;

    coord.y = 0;
    build_floor(game);
    while (game->pole.map[coord.y++])
    {
        coord.x = 0;
        while (game->pole.map[coord.x++])
        {
            map_check_one(game, coord.y, coord.x);
        }
    }
    return ;
}

void    map_check_one(t_game *game, int y, int x)
{
    if (!is_valid_char(game, y, x))
        return; //endgame()********************************************************************
    map_maker(game, y, x);
    return ;
}