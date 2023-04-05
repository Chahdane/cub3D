/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 04:48:53 by achahdan          #+#    #+#             */
/*   Updated: 2023/01/28 20:33:40 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	window_witdh(char **map, char w)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (x < j)
			x = j;
		i++;
	}
	if (w == 'w')
		return (x * 50);
	else
		return (i * 50);
}

int	map_len(char **map, int x)
{
	int	i;

	i = 0;
	while (map[x])
	{
		i++;
		x++;
	}
	return (i);
}

void	check_texture(t_map *mp)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;

	fd1 = open(mp->no, O_RDONLY);
	fd2 = open(mp->so, O_RDONLY);
	fd3 = open(mp->we, O_RDONLY);
	fd4 = open(mp->ea, O_RDONLY);
	if (fd1 == -1 || fd2 == -1
		|| fd3 == -1 || fd4 == -1)
		p_error();
}

void	my_mlx_pixel_put(t_infos *data, int x, int y, int color)
{
	char	*ret;

	ret = data->addr + (y * data->length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)ret = color;
}

int	cnv_clr(t_map *mp, int x, int y)
{
	return (*(int *)(mp->cub.imgs[mp->dir - 1].addr + (x % 50 * \
		mp->cub.imgs[mp->dir - 1].length + y % 50 * \
		(mp->cub.imgs[mp->dir - 1].bits_per_pixel / 4))));
}
