/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:38:46 by kmoutaou          #+#    #+#             */
/*   Updated: 2023/01/23 19:21:55 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_strcmp1(char *s1, char *s2)
{
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if ((ft_strlen(s1) == 0) || (ft_strlen(s2) == 0))
		return (s1[i] - s2[i]);
	while (s2[i] && s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
