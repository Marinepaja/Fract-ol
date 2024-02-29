/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:42:28 by mlaporte          #+#    #+#             */
/*   Updated: 2024/02/29 12:56:43 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

float	burning_ship(t_complex z);

void	draw_mandel(t_window *win)
{
	t_complex	z1;
	int			re;
	int			im;
	float		i;

	re = 0;
	while (re < WIDTH)
	{
		z1.a = 1.5 * (re - WIDTH / 2) / (0.5 * win->zoom * WIDTH)
			- 0.5 + win->offset->a;
		im = 0;
		while (im < HEIGHT)
		{
			z1.b = (im - HEIGHT / 2.0) / (0.5 * win->zoom
					* HEIGHT) + win->offset->b;
			i = mandelbrot(z1);
			img_pix_put(&(win->img), re, im, win->color * i);
			im ++;
		}
		re++;
	}
}

void	draw_ship(t_window *win)
{
	t_complex	z1;
	int			re;
	int			im;
	float		i;

	re = 0;
	while (re < WIDTH)
	{
		z1.a = (re - WIDTH / 2) / (0.4 * win->zoom * WIDTH) - 0.7
			+ win->offset->a;
		im = 0;
		while (im < HEIGHT)
		{
			z1.b = (im - HEIGHT / 2) / (0.4 * win->zoom * HEIGHT) - 0.3
				+ win->offset->b;
			i = burning_ship(z1);
			img_pix_put(&(win->img), re, im, win->color * i * 0.3);
			im ++;
		}
		re++;
	}
}

float	julia(t_complex z, t_complex c)
{
	float	i;
	float	mod;

	i = 0.0;
	while (i < 50)
	{
		i++;
		z = add_z(multiply_z(z, z), c);
		mod = sqrt(z.a * z.a + z.b * z.b);
		if (mod >= 2)
			return (i);
	}
	return (i);
}

void	draw_julia(t_window *win, t_complex *c)
{
	t_complex	z1;
	int			re;
	int			im;
	float		i;

	re = 0;
	while (re < WIDTH)
	{
		z1.a = (re - WIDTH / 2) / (0.5 * win->zoom * WIDTH) + win->offset->a;
		im = 0;
		while (im < HEIGHT)
		{
			z1.b = 1.5 * (im - HEIGHT / 2.0) / (0.5 * win->zoom
					* HEIGHT) + win->offset->b;
			i = julia(z1, *c);
			img_pix_put(&(win->img), re, im, win->color * i);
			im ++;
		}
		re++;
	}
}
