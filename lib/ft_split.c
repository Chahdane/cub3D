/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:40:53 by achahdan          #+#    #+#             */
/*   Updated: 2023/01/23 21:40:02 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_strucpy(char const *s, char c)
{
	char	*ptr;
	int		i;
	int		wd_len;

	wd_len = 0;
	i = 0;
	while (s[wd_len] && s[wd_len] != c)
		wd_len++;
	ptr = (char *)malloc(sizeof(char) * wd_len + 1);
	if (!ptr)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**table;
	int		i;
	int		j;
	char	*from;

	table = (char **) malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!table)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			from = (char *)&s[i];
			while (s[i + 1] && s[i + 1] != c)
				i++;
			table[j] = ft_strucpy(from, c);
			j++;
		}
		i++;
	}
	table[j] = 0;
	return (table);
}
