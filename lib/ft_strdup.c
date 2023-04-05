/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:28:45 by achahdan          #+#    #+#             */
/*   Updated: 2023/01/28 19:58:19 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strdup(const char *src)
{
	int		n;
	char	*dup;
	int		i;

	i = 0;
	n = 0;
	while (src[n])
		n++;
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup_one(const char *src)
{
	int		n;
	char	*dup;
	int		i;

	i = 0;
	n = 0;
	while (src[n])
		n++;
	dup = (char *)malloc(sizeof(char) * (n + 2));
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '1';
	dup[i + 1] = '\0';
	return (dup);
}
