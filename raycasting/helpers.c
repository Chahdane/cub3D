/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:19:05 by achahdan          #+#    #+#             */
/*   Updated: 2023/01/28 20:20:12 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	norm_str(char *str, char *str1, int i)
{
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == str1[0])
		{
			if (str[i] + 1 != '\0' && str1[1] != '\0' && str[i + 1] == str1[1])
			{
				if (!str1[2])
					return (1);
				else if (str[i + 2] == str1[2])
					return (1);
				else
					return (0);
			}
			else if (!str1[1])
				return (1);
			else
				return (0);
		}
		else
			return (0);
	}
	return (0);
}

int	str_check(char *str, char *str1)
{
	int	i;

	i = 0;
	return (norm_str(str, str1, i));
}

void	print_2dd(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	exit(0);
}

char	*ft_strdup2(char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	len = ft_strlen(s1);
	ptr = malloc (len * sizeof(char));
	i = 0;
	if (ptr == NULL)
		return (0);
	while (i < len - 1)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
