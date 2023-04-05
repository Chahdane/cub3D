/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:42:37 by achahdan          #+#    #+#             */
/*   Updated: 2023/01/23 21:47:16 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	checkwall(t_infos *inf, t_map *mp)
{
	inf->n = inf->a / 50;
	inf->s = inf->b / 50;
	if (mp->map[inf->n][inf->s] == ' ' || mp->map[inf->n][inf->s] == '1'
	|| mp->map[inf->n][inf->s] == '\0')
	{
		free(inf);
		return (0);
	}
	free(inf);
	return (1);
}

t_infos	*check_wall(t_map *mp, int i)
{
	t_infos	*t;
	int		a;

	a = 90;
	if (i < 2)
		a = 0;
	t = malloc(sizeof(t_infos));
	t->x0 = mp->player->x / 50;
	t->y0 = mp->player->y / 50;
	if (i == 0 || i == 3)
	{
		t->a = (mp->player->x - (10 * cos(a + mp->player->p_angle * M_PI \
		/ 180)));
		t->b = (mp->player->y - (10 * sin(a + mp->player->p_angle * M_PI \
		/ 180)));
	}
	else
	{
		t->a = (mp->player->x + (10 * cos(a + mp->player->p_angle * M_PI \
		/ 180)));
		t->b = (mp->player->y + (10 * sin(a + mp->player->p_angle * M_PI \
		/ 180)));
	}
	return (t);
}
