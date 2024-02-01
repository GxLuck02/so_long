/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreichl <ttreichl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:19:58 by ttreichl          #+#    #+#             */
/*   Updated: 2024/01/23 18:34:44 by ttreichl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

t_point     get_screen_size(t_game *game)
{
    t_point     size;

    mlx_get_screen_size(game->mlx_pointer, &size.x, &size.y);
    return (size);
}

bool    is_larger_than_screen(t_game *game)
{
    t_point     screen_size;

    screen_size = get_screen_size(game);
    return ((game->pole.length * SPRITE_SIZE) > screen_size.x || (game->pole.height * SPRITE_SIZE) > screen_size.y);
}