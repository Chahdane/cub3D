/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 05:02:39 by achahdan          #+#    #+#             */
/*   Updated: 2023/01/28 21:57:55 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	hook_one(int key, t_map *mp)
{
	if (key == 123)
		mp->event[0] = 1;
	else if (key == 124)
		mp->event[1] = 1;
	else if (key == 1 || key == 125)
		mp->event[2] = 1;
	else if (key == 13 || key == 126)
		mp->event[3] = 1;
	else if (key == 0)
		mp->event[4] = 1;
	else if (key == 2)
		mp->event[5] = 1;
	else if (key == 53)
		exit(1);
	return (0);
}

int	hook_zero(int key, t_map *mp)
{
	if (key == 123)
		mp->event[0] = 0;
	else if (key == 124)
		mp->event[1] = 0;
	else if (key == 1 || key == 125)
		mp->event[2] = 0;
	else if (key == 13 || key == 126)
		mp->event[3] = 0;
	else if (key == 0)
		mp->event[4] = 0;
	else if (key == 2)
		mp->event[5] = 0;
	return (0);
}

t_map	*init_mp(t_map *mp)
{
	mp->map_height = 0;
	mp->map_width = 0;
	mp->player = ft_infos(mp);
	mp->map = remake_angles(mp);
	mp->floor = get_rgb(mp->f);
	mp->cel = get_rgb(mp->c);
	while (mp->map_width < 6)
	{
		mp->event[mp->map_width] = 0;
		mp->map_width++;
	}
	mp->map_width = 0;
	mp->k = 0;
	mp->map_height = ft_strlen(mp->map[0]);
	while (mp->map[mp->map_width])
	{
		if (mp->map_height < ft_strlen(mp->map[mp->map_width]))
			mp->map_height = ft_strlen(mp->map[mp->map_width]);
		mp->map_width++;
	}
	return (mp);
}

unsigned long	get_rgb(char *str)
{
	char			**tab;
	unsigned long	ret;
	int				i;

	i = 0;
	tab = ft_split(str, ',');
	ret = ((ft_atoi(tab[0]) & 0xff) << 16) + ((ft_atoi(tab[1]) & 0xff) << 8) + \
	(ft_atoi(tab[2]) & 0xff);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (ret);
}

int	ft_exit(t_map *mp)
{
	exit(1);
	return (0);
}
