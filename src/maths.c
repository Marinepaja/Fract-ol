/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:44:32 by mlaporte          #+#    #+#             */
/*   Updated: 2024/02/29 12:57:03 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complex	add_z(t_complex z1, t_complex z2)
{
	t_complex	z3;

	z3.a = z2.a + z1.a;
	z3.b = z2.b + z1.b;
	return (z3);
}

t_complex	multiply_z(t_complex z1, t_complex z2)
{
	t_complex	z3;

	z3.a = z1.a * z2.a - z1.b * z2.b;
	z3.b = z2.a * z1.b + z1.a * z2.b;
	return (z3);
}

t_complex	abs_z(t_complex z)
{
	t_complex	z1;

	if (z.a < 0)
		z1.a = -z.a;
	if (z.b < 0)
		z1.b = -z.b;
	return (z1);
}

float	mandelbrot(t_complex c)
{
	t_complex	z;
	float		i;
	float		mod;

	i = 0.0;
	z.a = 0;
	z.b = 0;
	while (i < 50)
	{
		z = add_z(multiply_z(z, z), c);
		mod = sqrt(z.a * z.a + z.b * z.b);
		if (mod >= 4)
			return (i);
		i++;
	}
	return (i);
}

float	burning_ship(t_complex c)
{
	t_complex	z;
	float		i;
	float		temp;

	i = 0.0;
	z.a = 0;
	z.b = 0;
	while (i < 100 && z.a * z.a + z.b * z.b <= 16)
	{
		temp = z.a * z.a - z.b * z.b + c.a;
		z.b = fabs(2 * z.a * z.b) + c.b;
		z.a = temp;
		i++;
	}
	return (i);
}
