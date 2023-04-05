/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:33:13 by achahdan          #+#    #+#             */
/*   Updated: 2023/01/28 20:41:33 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	render_3d(t_map *mp, t_pic *mlx)
{
	t_infos	*inf;

	inf = malloc(sizeof(t_infos));
	inf->x = 20;
	inf->z = 0;
	while (inf->z < WIDTH)
	{
		inf->h = mp->player->x;
		inf->g = mp->player->y;
		inf->i = inf->h + (1000 * cos((mp->player->p_angle + inf->x) * \
		M_PI / 180));
		inf->j = inf->g + (1000 * sin((mp->player->p_angle + inf->x) * \
		M_PI / 180));
		dda(inf, mp);
		if (inf->x > -100)
			inf->x -= (float)1 / (WIDTH / 50);
		inf->z++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->wind, mp->img.img, 1, 1);
	free(inf);
}

t_infos	*get_tinfos(t_infos *inf)
{
	inf->x0 = inf->a / 50;
	inf->y0 = inf->b / 50;
	inf->n = (inf->a + inf->xint) / 50;
	inf->s = (inf->b + inf->yint) / 50;
	return (inf);
}

int	dda(t_infos *inf, t_map *mp)
{
	t_infos	img;

	mp->player->x_distance = mp->player->x;
	mp->player->y_distance = mp->player->y;
	inf->dx = inf->i - inf->h;
	inf->dy = inf->j - inf->g;
	if (abs(inf->dx) > abs(inf->dy))
		inf->v_abs = abs(inf->dx);
	else
		inf->v_abs = abs(inf->dy);
	inf->xint = inf->dx / (float) inf->v_abs;
	inf->yint = inf->dy / (float) inf->v_abs;
	inf->a = inf->h;
	inf->b = inf->g;
	dda_two(inf, mp);
	return (0);
}

void	dda_two(t_infos *inf, t_map *mp)
{
	while (mp->map[(int)inf->a / 50][(int)inf->b / 50] != '1'
		&& mp->map[(int)inf->a / 50][(int)inf->b / 50] != '\0'
	)
	{
		inf->a += inf->xint;
		inf->b += inf->yint;
		mp->player->x_distance += inf->xint;
		mp->player->y_distance += inf->yint;
	}
	directions(mp, inf->a, inf->b, '1');
	mp->player->distance_to_wall = sqrt(pow((mp->player->x_distance
					- mp->player->x), 2)
			+ pow((mp->player->y_distance - mp->player->y), 2));
	inf->c = (mp->player->p_angle * M_PI / 180)
		- (((mp->player->p_angle + inf->x) * M_PI) / 180);
	mp->player->distance_to_wall = mp->player->distance_to_wall * cos(inf->c);
	inf->wall = (50 * HEIGHT) / mp->player->distance_to_wall;
	draw_3d(mp, inf);
}

void	draw_3d(t_map *mp, t_infos *inf)
{
	int	i;
	int	color;

	i = 0;
	while (i < HEIGHT && inf->z < WIDTH)
	{
		if (i <= (int)(HEIGHT - inf->wall) / 2)
			my_mlx_pixel_put(&mp->img, inf->z, i, mp->cel);
		else if (i < (int)(((HEIGHT - inf->wall) / 2) + inf->wall))
		{
			if (mp->dir == 1 || mp->dir == 2)
				mp->agnle = fmod(inf->b / 50, 1);
			else if (mp->dir == 3 || mp->dir == 4)
				mp->agnle = fmod(inf->a / 50, 1);
			mp->agnle *= 50;
			color = cnv_clr(mp, (int)(((i - ((HEIGHT - inf->wall) / 2)) * 50) \
			/ inf->wall), mp->agnle);
			my_mlx_pixel_put(&mp->img, inf->z, i, color);
		}
		else
			my_mlx_pixel_put(&mp->img, inf->z, i, mp->floor);
		i++;
	}
}
