/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:30:20 by kmoutaou          #+#    #+#             */
/*   Updated: 2023/01/28 19:46:08 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	sign(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '+')
		{
			if (!is_number(s[i + 1]))
				return (1);
			count++;
		}
		i++;
	}
	if (count > 1)
		return (1);
	return (0);
}

int	nb_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	rgb_cond1(char *colors)
{
	char	**rgb;
	int		fault;

	fault = 0;
	rgb = ft_split(colors, ',');
	if (!rgb[0] || ft_atoi1(rgb[0]) < 0 || ft_atoi1(rgb[0]) > 255 || \
	sign(rgb[0]) || nb_characters(rgb[0]) > 3 || \
	nb_digits(ft_atoi1(rgb[0])) != nb_characters(rgb[0]))
		fault++;
	if (!rgb[1] || ft_atoi1(rgb[1]) < 0 || ft_atoi1(rgb[1]) > 255 || \
	sign(rgb[1]) || nb_characters(rgb[1]) > 3 || \
	nb_digits(ft_atoi1(rgb[1])) != nb_characters(rgb[1]))
		fault++;
	if (!rgb[2] || ft_atoi1(rgb[2]) < 0 || ft_atoi1(rgb[2]) > 255 || \
	sign(rgb[2]) || nb_characters(rgb[2]) > 3 || \
	nb_digits(ft_atoi1(rgb[2])) != nb_characters(rgb[2]))
		fault++;
	free_2d(rgb);
	if (fault > 0)
		return (1);
	return (0);
}

int	rgb_cond2(char *colors)
{
	char	**rgb;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rgb = ft_split(colors, ',');
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j] && is_space(rgb[i][j]))
			j++;
		while (rgb[i][j])
		{
			if (!is_number(rgb[i][j]) && rgb[i][j] != '+' && rgb[i][j] != ' ')
			{
				free_2d(rgb);
				return (1);
			}
			j++;
		}
		i++;
	}
	free_2d(rgb);
	return (0);
}

int	check_rgb(char *colors)
{
	int	i;
	int	exists;

	i = 0;
	exists = 0;
	if (!colors)
		return (1);
	if (rgb_cond2(colors) || rgb_cond1(colors))
		return (1);
	while (colors[i])
	{
		if (colors[i] == ',')
			exists += 1;
		i++;
	}
	if (exists != 2)
		return (1);
	return (0);
}
