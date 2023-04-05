/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:21:26 by achahdan          #+#    #+#             */
/*   Updated: 2023/01/28 21:18:49 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	directions(t_map *mp, float a, float b, char c)
{
	if (mp->map[(int)((a - 1) / 50)][(int)b / 50] != c)
		mp->dir = 1;
	if (mp->map[(int)((a + 1) / 50)][(int)b / 50] != c)
		mp->dir = 2;
	if (mp->map[(int)a / 50][(int)((b - 1) / 50)] != c)
		mp->dir = 3;
	if (mp->map[(int)a / 50][(int)((b + 1) / 50)] != c)
		mp->dir = 4;
}

t_map	*init_texture(t_map *mp, t_pic *mlx)
{
	int		z;
	int		i;
	char	*names[4];

	z = HEIGHT;
	check_texture(mp);
	mp->cub.imgs = malloc(sizeof(t_infos) * 4);
	i = 0;
	names[0] = mp->no;
	names[1] = mp->ea;
	names[2] = mp->so;
	names[3] = mp->we;
	while (i < 4)
	{
		mp->cub.imgs[i].img = mlx_xpm_file_to_image(mlx->mlx, names[i], &z, &z);
			mp->cub.imgs[i].addr = mlx_get_data_addr(mp->cub.imgs[i].img, \
			&mp->cub.imgs[i].bits_per_pixel, &mp->cub.imgs[i].length, \
			&mp->cub.imgs[i].endian);
		i++;
	}
	return (mp);
}

void	run_hoooks(t_map *mp, t_pic *mlx)
{
	mlx_hook(mlx->wind, 2, 1L << 0, hook_one, mp);
	mlx_hook(mlx->wind, 3, 1L << 0, hook_zero, mp);
	mlx_loop_hook(mlx->mlx, move_player, mp);
	mlx_hook(mlx->wind, 17, 0, ft_exit, mp);
	mlx_loop(mlx->mlx);
}

void	p_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	change_xy(t_map *map, int angle, char sign, int wall)
{
	t_infos	*wall_a;

	wall_a = check_wall(map, wall);
	if (!checkwall(wall_a, map))
		return ;
	if (sign == '+')
	{
		map->player->x += 7 * cos((angle + map->player->p_angle) * M_PI / 180);
		map->player->y += 7 * sin(angle + map->player->p_angle * M_PI / 180);
	}
	else
	{
		map->player->x -= 7 * cos((angle + map->player->p_angle) * M_PI / 180);
		map->player->y -= 7 * sin(angle + map->player->p_angle * M_PI / 180);
	}
}
