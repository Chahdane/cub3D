/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:37:59 by kmoutaou          #+#    #+#             */
/*   Updated: 2023/01/24 15:12:17 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_convert(char *str, int i, int result, int sign)
{
	while (is_number(str[i]))
	{
		if ((((unsigned long)result * 10) + (str[i] - '0'))
			> (unsigned long)9223372036854775807 && sign > 0)
			return (-1);
		if ((((unsigned long)result * 10) + (str[i] - '0'))
			> (unsigned long)9223372036854775807 + 1 && sign < 0)
			return (0);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_atoi1(char *str)
{
	int	result;
	int	sign;
	int	repeat;
	int	i;

	i = 0;
	repeat = 0;
	result = 0;
	sign = 1;
	while (((str[i] >= 9 && str[i] <= 13) || (str[i] == 32)))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = ft_convert(str, i, result, sign);
	return (result);
}
