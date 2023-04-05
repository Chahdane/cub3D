/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:42:08 by kmoutaou          #+#    #+#             */
/*   Updated: 2023/01/28 15:40:16 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_zero(char **map, int i, int j)
{
	if (!map)
		return (1);
	while (map[i][j])
	{
		if (map[i][j] == '0')
		{
			if (is_space(map[i][j + 1]) || is_space(map[i][j - 1]))
				return (1);
			if (map[i - 1] && !is_letter(map[i - 1][j]) && \
			map[i - 1][j] != '1' && map[i - 1][j] != '0')
				return (1);
			if (map[i + 1] && !is_letter(map[i + 1][j]) && \
			map[i + 1][j] != '1' && map[i + 1][j] != '0')
				return (1);
		}
		j++;
	}
	return (0);
}

int	check_map_walls(char **map, int last)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!map)
		return (1);
	while (i < last)
	{
		j = get_index(map, i);
		if (map[i][j] != '1')
			return (1);
		if (map[i][ft_strlen(map[i]) - 1] != '1' && \
		!is_space(map[i][ft_strlen(map[i]) - 1]))
			return (1);
		if (check_zero(map, i, j))
			return (1);
		i++;
	}
	return (0);
}
