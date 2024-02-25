/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:51:55 by mlaporte          #+#    #+#             */
/*   Updated: 2024/02/25 15:29:12 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	ft_len(char *num)
{
	int	len;

	len = 0;
	while (*num && ft_isdigit(*num))
	{
		num++;
		len++;
	}
	return (len);
}

float	ft_atof(char *num)
{
	float	ent;
	float	dec;
	float	sign;
	int		len;

	sign = 1.0;
	ent = (float)abs(ft_atoi(num));
	if (*num && *num == '-')
	{
		sign *= -1;
		num++;
	}
	while (*num && ft_isdigit(*num))
		num++;
	if (*num && (*num == '.' || *num == ','))
	{
		num++;
		dec = ft_atoi(num);
		len = ft_len(num);
		while (len--)
			dec /= 10;
	}
	return (ent + sign * dec);
}
