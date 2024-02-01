/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreichl <ttreichl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:05:46 by ttreichl          #+#    #+#             */
/*   Updated: 2024/02/01 15:00:42 by ttreichl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	free_map(t_game *game)// delet all string of map
{
	while (game->pole.height > 0)
	{
		free(game->pole.map[game->pole.height -1]);//use height for start at the end of table
		game->pole.height--;
	}
	free(game->pole.map);
	return ;
}