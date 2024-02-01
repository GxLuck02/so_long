/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cheker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreichl <ttreichl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:11:23 by ttreichl          #+#    #+#             */
/*   Updated: 2024/01/26 19:45:34 by ttreichl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int     is_valid_length(t_game *game) //check length of line 
{
    int     x;
    int     i;
    int     y;

    i = 0;
    x = ft_strlen(game->pole.map[0]);
    while (game->pole.map[i++] != NULL)
    {
        y = ft_strlen(game->pole.map[i]);
        if (x != y)
        {
            free_map(game);
            //endgame();
            return (0);
        }
    }
    return (x);
}

bool    is_valid_char(t_game *game, int y, int x)
{
    if (!(ft_strchr("01ECP", game->pole.map[y][x])))
        return (false);
    return (true);
}