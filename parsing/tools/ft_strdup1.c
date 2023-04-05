/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:20:18 by kmoutaou          #+#    #+#             */
/*   Updated: 2023/01/23 19:17:11 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*ft_strdup1(char *s1)
{
	char	*s2;
	int		i;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * len + 1);
	if (!s2)
		return (s2);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
