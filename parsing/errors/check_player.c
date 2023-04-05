/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:33:43 by kmoutaou          #+#    #+#             */
/*   Updated: 2023/01/28 13:20:16 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_player(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map)
		return (1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_letter(map[i][j]))
			{
				if (is_space(map[i][j - 1]) || is_space(map[i][j + 1]) || \
				is_space(map[i - 1][j]) || is_space(map[i + 1][j]))
					return (1);
			}
			j++;
		}
		i++ ;
	}
	return (0);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_existence(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	if (!map)
		return (1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]))
				k++;
			if (is_letter(map[i][j]) && !is_player(map[i][j]))
				return (1);
			j++;
		}
		i++ ;
	}
	if (k != 1)
		return (1);
	return (0);
}
