/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:47:49 by kmoutaou          #+#    #+#             */
/*   Updated: 2023/01/28 17:24:15 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	file_size(char	**file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i])
	{
		if (file[i][0] == '\0')
			j++ ;
		i++;
	}
	return (i - j);
}

int	array_size(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	nb_characters(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (is_number(s[i]))
			count++;
		i++;
	}
	return (count);
}
