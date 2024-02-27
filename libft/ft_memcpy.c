/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:38:50 by mlaporte          #+#    #+#             */
/*   Updated: 2023/05/23 10:48:34 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destin;
	const unsigned char	*source;
	size_t				i;

	if (!dest && !src)
		return (0);
	destin = dest;
	source = src;
	i = 0;
	while (i < n)
	{
		destin[i] = source[i];
		i++;
	}
	return (destin);
}
