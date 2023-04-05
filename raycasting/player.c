/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:07:46 by achahdan          #+#    #+#             */
/*   Updated: 2023/01/28 21:19:14 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_infos	*ft_infos(t_map *mp)
{
	t_infos		info;
	t_infos		*player;

	player = malloc (sizeof(t_infos));
	info.i = -1;
	info.n = 0;
	while (mp->map[++info.i])
	{
		info.j = -1;
		info.y = 0;
		while (mp->map[info.i][++info.j])
		{
			if (mp->map[info.i][info.j] == 'N' || mp->map[info.i][info.j] == 'S'\
			|| mp->map[info.i][info.j] == 'W' || mp->map[info.i][info.j] == 'E')
			{
				player->x = info.n + 20;
				player->y = info.y + 20;
			}
			info.y += 50;
		}
		info.n += 50;
	}
	return (player);
}

char	**str_one(char **map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (map[i])
	{
		tmp = ft_strdup_one(map[i]);
		free(map[i]);
		map[i] = tmp;
		i++;
	}
	return (map);
}

char	**remake_angles(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	remake(map);
	remake2(map);
	str_one(map->map);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			map = player_angle(map, i, j);
			j++;
		}
		i++;
	}
	return (map->map);
}

char	**remake2(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	remake(map);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == ' ')
			{
				map->map[i][j] = '1';
			}
			j++;
		}
		i++;
	}
	return (map->map);
}

char	**remake(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'S' || map->map[i][j] == 'W'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'N')
			{
				if (map->map[i + 1][j - 1] == ' ')
					map->map[i + 1][j - 1] = '1';
			}
			j++;
		}
		i++;
	}
	return (map->map);
}
