/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:10:04 by kmoutaou          #+#    #+#             */
/*   Updated: 2023/01/16 18:44:13 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s12;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	s12 = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s12)
		return (NULL);
	if (s1)
	{
		while (s1[i])
			s12[j++] = s1[i++];
		i = 0;
	}
	if (s2)
	{
		while (s2[i])
			s12[j++] = s2[i++];
	}
	s12[j] = '\0';
	free(s1);
	return (s12);
}

int	afterline_size(char *text, int i)
{
	int	size;

	size = 0;
	if (!text)
		return (0);
	while (text[i])
	{	
		i++;
		size++;
	}
	return (size);
}

int	line_size(char *text)
{
	int	i;

	i = 0;
	if (!text)
		return (0);
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] && text[i] == '\n')
		i++;
	return (i);
}
