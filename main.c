/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 06:05:05 by achahdan          #+#    #+#             */
/*   Updated: 2023/01/28 20:33:40 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	free_2d(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++ ;
	}
	free(s);
}

int	check_extention(char *str)
{
	char	**path;
	int		last;

	if (!str)
		return (1);
	if (ft_strlen(str) < 5)
		return (1);
	path = ft_split(str, '.');
	last = array_size(path) - 1;
	if (ft_strcmp1(path[last], "cub") != 0)
	{
		free_2d(path);
		return (1);
	}
	free_2d(path);
	return (0);
}

void	error_exit(void)
{
	printf("Error\nYour scene description file is not valid!\n");
	exit(1);
}

void	run_cub3d(t_pic *mlx, t_map *mp)
{
	mlx->mlx = mlx_init();
	mlx->wind = mlx_new_window(mlx->mlx, HEIGHT, WIDTH, "cub3d");
	mp->img.img = mlx_new_image(mlx->mlx, HEIGHT, WIDTH);
	mp->img.addr = mlx_get_data_addr(mp->img.img, \
	&mp->img.bits_per_pixel, &mp->img.length, &mp->img.endian);
	mp = init_texture(mp, mlx);
	mp = init_mp(mp);
	run_hoooks(mp, mlx);
}

int	main(int ac, char **av)
{
	char	**map;
	t_map	*mp;
	t_pic	*mlx;

	if (ac != 2 || check_extention(av[1]))
		error_exit();
	map = read_map(av[1]);
	if (!map)
		error_exit();
	if (map)
	{
		mp = parse_map(map);
		if (detect_error(mp) > 0)
			error_exit();
		mlx = malloc(sizeof(t_pic));
		if (mp != NULL)
		{
			run_cub3d(mlx, mp);
		}
	}
}
