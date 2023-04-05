/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:35:50 by kmoutaou          #+#    #+#             */
/*   Updated: 2023/01/14 18:22:26 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *text)
{
	int	i;

	i = 0;
	if (!text)
		return (0);
	while (text[i])
	{
		if (text[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *text)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!text)
		return (NULL);
	if (text[0] == '\0')
		return (NULL);
	line = (char *)malloc(sizeof(char) * line_size(text) + 1);
	if (!line)
		return (NULL);
	while (text[i] && text[i] != '\n')
	{
		line[j] = text[i];
		i++;
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_afterline(char *text)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!text)
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	if (text[i] && text[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * afterline_size(text, i) + 1);
	if (!line)
		return (NULL);
	while (text[i])
		line[j++] = text[i++];
	line[j] = '\0';
	free(text);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*text;
	int			test;
	char		buff[2];
	char		*line;

	if (fd < 0)
		return (NULL);
	test = 1;
	while (test > 0 && !check_newline(text))
	{
		test = read (fd, buff, 1);
		if (test < 0)
		{
			free(text);
			return (NULL);
		}
		buff[test] = '\0';
		text = ft_strjoin(text, buff);
	}
	line = get_line(text);
	text = get_afterline(text);
	return (line);
}
