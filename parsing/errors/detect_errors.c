/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:56:12 by kmoutaou          #+#    #+#             */
/*   Updated: 2023/01/26 20:40:56 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	detect_error(t_map *map)
{
	int		last;
	int		last_file;
	char	**map_only;
	int		fault;

	fault = 0;
	map_only = final_map(map->map);
	if (map_only == NULL)
		error_exit();
	last_file = array_size(map->map);
	last = array_size(map_only) - 1;
	if (!map || !map->map || !map->no || !map->so || !map->we || !map->ea || \
	check_path(map) || check_rgb(map->c) || check_rgb(map->f) || \
	!is_one(map_only[0]) || !is_one(map_only[last]) || \
	check_map_walls(map_only, last) || check_player(map_only) || \
	check_existence(map_only) || !ft_strcmp1(map->map[last_file - 1], "") || \
	map_check(map_only, map->map) || file_size(map->map) + 1 > last + 1 + 6 || \
	ft_strcmp1(map->map[last_file - 1], map_only[last]) > 0)
		fault += 1;
	free_2d(map_only);
	return (fault);
}
