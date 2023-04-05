/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:14:18 by kmoutaou          #+#    #+#             */
/*   Updated: 2023/01/16 18:44:25 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		afterline_size(char *text, int i);
int		line_size(char *text);
char	*get_next_line(int fd);
char	*get_afterline(char *text);
char	*get_line(char *text);
int		check_newline(char *text);

#endif