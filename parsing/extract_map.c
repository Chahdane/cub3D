/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:14:40 by kmoutaou          #+#    #+#             */
/*   Updated: 2023/01/23 22:16:36 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	**read_map(char *file)
{
	char	*line;
	char	**map;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * 100);
	if (!map)
		return (NULL);
	i = 0;
	while (line)
	{
		map[i] = ft_strdup1(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = 0;
	return (map);
}

char	**final_map(char **mp)
{
	int		i;
	int		j;
	int		k;
	char	**map;

	i = 0;
	k = 0;
	if (!mp)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * 100);
	if (!map)
		return (NULL);
	while (mp[i])
	{
		j = 0;
		while (is_space(mp[i][j]))
			j++;
		if (mp[i][j] && is_number(mp[i][j]))
			map[k++] = ft_strdup1(mp[i]);
		i++;
	}
	if (k == 0)
		return (NULL);
	map[k] = 0;
	return (map);
}
