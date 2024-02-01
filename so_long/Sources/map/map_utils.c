/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreichl <ttreichl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:10:15 by ttreichl          #+#    #+#             */
/*   Updated: 2024/01/31 16:59:20 by ttreichl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int   open_file(char *path)
{
    int     fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error\nInvalide file\n");
        exit (1);
    }
    return(fd);
}

t_counter   new_counter() // reboot counter
{
    t_counter   cne;
    
    cne.empty = 0;
    cne.collectible = 0;
    cne.exit = 0;
    cne.start = 0;
    cne.movements = 0;
    return (cne);
}

void    count_element(t_counter *cne, char c)
{
    if (c == '0')
        cne->empty++;
    else if (c == 'E')
        cne->exit++;
    else if (c == 'C')
        cne->collectible++;
    else if (c == 'P')
        cne->start++;
}

void    is_element_nbr_valid(t_counter *cne, char *tmp)
{
    if (!(cne->collectible > 0 && cne->exit == 1 && cne->start == 1 && cne->empty > 0))
    {
        free (tmp);
        //endgame ();
    }
}