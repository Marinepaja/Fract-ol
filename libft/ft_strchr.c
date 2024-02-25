/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:32:47 by mlaporte          #+#    #+#             */
/*   Updated: 2023/05/13 10:55:01 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	chr;

	chr = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == chr)
			return ((char *)(s + i));
		else
			i++;
	}
	if (chr == '\0')
		return ((char *)(s + i));
	return (0);
}
