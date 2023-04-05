/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:41:27 by kmoutaou          #+#    #+#             */
/*   Updated: 2023/01/28 15:36:34 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_letter(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_one(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i] && is_space(line[i]))
			i++;
	while (line[i])
	{
		if (line[i] != '1' && !is_space(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	get_index(char **map, int i)
{
	int	j;

	j = 0;
	if (!map)
		return (0);
	while (map[i][j] && is_space(map[i][j]))
		j++;
	return (j);
}
