/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:35:13 by kmoutaou          #+#    #+#             */
/*   Updated: 2023/01/23 21:38:32 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	map_check1(char **map_only, char **file, int k)
{
	int	i;

	i = 0;
	while (map_only[i] && file[k])
	{
		if (ft_strcmp1(map_only[i], file[k]) != 0)
			return (1);
		i++;
		k++;
	}
	return (0);
}

int	map_check(char **map_only, char **file)
{
	int	i;
	int	j;

	i = 0;
	if (!map_only || !file)
		return (1);
	while (file[i])
	{
		j = get_index(file, i);
		if (file[i][j] == '1')
		{
			if (!ft_strcmp1(file[i], map_only[0]))
			{
				if (map_check1(map_only, file, i))
					return (1);
				else
					return (0);
			}
		}
		i++;
	}
	return (0);
}
