/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreichl <ttreichl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:50:22 by ttreichl          #+#    #+#             */
/*   Updated: 2024/02/01 15:03:54 by ttreichl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
*/

int	main(int argc, char *argv[])
{
	t_game	game;

    /*if (argc == 2 && (check_ber_file(argv[1]) == false)) // check type of file (.ber)
    {
        //endgame ();
    }
    else if (argc > 2)// check number of argument
    {
        //endgame ();
    }
    else if (argc == 2 && (check_ber_file(argv[1]) == true))
    {
        init_game(&game, argv[1]);
    }*/
	if (argc == 2)
		init_game(&game, argv[1]);
	return (0);
}
/*
static bool check_ber_file(const char *argv) // check format file
{
    char    *string;
    
    string = ft_strrchr(argv, '.');
    if (string)
        return (ft_strcmp(string, ".ber") == 0);
    return (false);
}*/

void	init_game(t_game *game, char *path)
{
	init_map(game, path);
	init_window(game);
	init_image(game);
	render_map(game);
	mlx_loop(game->mlx_pointer);
}
