/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 02:47:39 by achahdan          #+#    #+#             */
/*   Updated: 2023/01/28 20:50:15 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*check_str_path(char *str, char *path)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str_check(str + i, path) != 0)
			return (str);
		i++;
	}
	return (NULL);
}

char	*trim_str(char *str, char *dir)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dir);
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else if (str_check(str + i, dir))
			i += len;
		else
			break ;
	}
	return (str + i);
}

int	space_check(char *str, char *dir)
{
	int	i;
	int	len;
	int	k;

	i = 0;
	len = ft_strlen(dir);
	k = 0;
	while (str[i])
	{
		while (is_space(str[i]))
			i++;
		if (str_check(str + i, dir))
		{
			k = i + len;
			break ;
		}
		i++;
	}
	if (k != 0 && !is_space(str[k]))
		return (0);
	return (1);
}

char	*get_path(char **map, char *dir)
{
	int		i;
	int		j;
	char	*ret;

	ret = NULL;
	i = 0;
	j = 0;
	while (map[i])
	{
		ret = check_str_path(map[i], dir);
		if (ret)
		{
			if (!space_check(ret, dir))
				error_exit();
			ret = trim_str(ret, dir);
			return (ret);
		}
		i++;
	}
	return (NULL);
}

t_map	*parse_map(char **mm)
{
	int		i;
	int		j;
	t_map	*map;

	i = 0;
	j = 0;
	map = malloc(sizeof(t_map));
	map->no = get_path(mm, "NO");
	map->no = ft_strtrim1(map->no, " ");
	map->so = get_path(mm, "SO");
	map->so = ft_strtrim1(map->so, " ");
	map->we = get_path(mm, "WE");
	map->we = ft_strtrim1(map->we, " ");
	map->ea = get_path(mm, "EA");
	map->ea = ft_strtrim1(map->ea, " ");
	map->f = get_path(mm, "F");
	map->c = get_path(mm, "C");
	map->map = malloc(sizeof(char *) * 1000);
	while (mm[++i])
		map->map[j++] = ft_strdup(mm[i]);
	map->map[j] = 0;
	return (map);
}
