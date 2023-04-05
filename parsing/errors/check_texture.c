/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:45:25 by kmoutaou          #+#    #+#             */
/*   Updated: 2023/01/28 20:06:32 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	texture_extension(char *link)
{
	char	**path;
	char	*ext;
	int		i;
	int		j;

	path = ft_split(link, '.');
	ext = "xpm";
	i = 0;
	j = 0;
	while (path[i])
		i++;
	if (ft_strcmp1(path[i - 1], ext) != 0)
	{
		free_2d(path);
		return (1);
	}
	free_2d(path);
	return (0);
}

int	check_path(t_map *map)
{
	if (!map || !map->no || !map->so || !map->we || !map->ea)
		return (1);
	if (open(map->no, O_RDONLY) < 0 || texture_extension(map->no))
		return (1);
	if (open(map->so, O_RDONLY) < 0 || texture_extension(map->so))
		return (1);
	if (open(map->we, O_RDONLY) < 0 || texture_extension(map->we))
		return (1);
	if (open(map->ea, O_RDONLY) < 0 || texture_extension(map->ea))
		return (1);
	return (0);
}
