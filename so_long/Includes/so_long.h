/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreichl <ttreichl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:24:44 by ttreichl          #+#    #+#             */
/*   Updated: 2024/02/01 15:28:43 by ttreichl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "so_long_utils.h"
#include "so_long_path.h"
#include "../Libft/ft_printf.h"


#include "../minilibx/mlx.h"
#include <stdio.h>//printf
#include <stdlib.h>//malloc
#include <unistd.h>//read,close,write
#include <fcntl.h>//open, 0_RDONLY
#include <stdbool.h>//bool

int             open_file(char *path);
t_counter       new_counter();
t_counter       start_counter(char *string_map);
void            count_element(t_counter *cne, char c);
void            is_element_nbr_valid(t_counter *cne, char *tmp);
void            init_map(t_game *game, char *path);
void            init_game(t_game *game, char *path);
void            free_map(t_game *game);
void            read_map(t_game *game, int fd);
void            init_window(t_game *game);
bool            is_larger_than_screen(t_game *game);
void            init_image(t_game *game);
void            render_map(t_game *game);
void            map_check_one(t_game *game, int y, int x);
bool            is_valid_char(t_game *game, int y, int x);
void            build_floor(t_game *game);
void            check_surrounded_wall(t_game *game);
int             is_valid_length(t_game *game);
t_image         new_sprite(void *mlx, char *path);
//static bool     check_ber_file(const char *argv);

#endif