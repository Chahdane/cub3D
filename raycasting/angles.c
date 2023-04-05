/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:20:35 by achahdan          #+#    #+#             */
/*   Updated: 2023/01/28 21:20:48 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_map	*player_angle(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'N')
		map->player->p_angle = 175;
	else if (map->map[i][j] == 'W')
		map->player->p_angle = 265;
	else if (map->map[i][j] == 'S')
		map->player->p_angle = -5;
	else if (map->map[i][j] == 'E')
		map->player->p_angle = 85;
	else
		return (map);
	map->map[i][j] = '0';
	return (map);
}

int	move_player(t_map *mp, t_pic *mlx)
{
	if (mp->event[0] == 1)
		mp->player->p_angle += 5;
	else if (mp->event[1] == 1)
		mp->player->p_angle -= 5;
	else if (mp->event[2] == 1)
		change_xy(mp, 0, '-', 0);
	else if (mp->event[3] == 1)
		change_xy(mp, 0, '+', 1);
	else if (mp->event[4] == 1)
		change_xy(mp, 90, '+', 2);
	else if (mp->event[5] == 1)
		change_xy(mp, 90, '-', 3);
	render_3d(mp, mlx);
	return (0);
}
