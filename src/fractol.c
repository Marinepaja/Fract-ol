/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:08:59 by mlaporte          #+#    #+#             */
/*   Updated: 2024/02/25 15:22:19 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	change_color(t_window *win)
{
	int		new_col;

	new_col = rand();
	while (new_col > 0xFFFFFF)
		new_col = rand();
	win->color = new_col;
}

void	change_real(t_complex *c)
{
	if (!c)
		return ;
	if (c->a < 1.40)
		c->a += 0.01;
	else
		c->a = -1.4;
}

void	change_im(t_complex *c)
{
	if (!c)
		return ;
	if (c->b < 1)
		c->b += 0.01;
	else
		c->b = -1;
}

void	draw(t_window *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	if (win->set == MANDELBROT)
		draw_mandel(win);
	else if (win->set == JULIA)
		draw_julia(win, win->c);
	else if (win->set == SHIP)
		draw_ship(win);
	else
		exit_mlx(win);
}

int	deal_key(int key, t_window *win)
{
	if (key == K_ESC)
		exit_mlx(win);
	else if (key == K_UP)
		win->offset->b -= 0.1 / win->zoom;
	else if (key == K_DOWN)
		win->offset->b += 0.1 / win->zoom;
	else if (key == K_RIGHT)
		win->offset->a += 0.1 / win->zoom;
	else if (key == K_LEFT)
		win->offset->a -= 0.1 / win->zoom;
	else if (key == M_UP)
		win->zoom *= 1.2;
	else if (key == M_DOWN)
		win->zoom *= 0.8;
	else if (key == K_C)
		change_color(win);
	else if (key == K_I && win->set == JULIA)
		change_im(win->c);
	else if (key == K_R && win->set == JULIA)
		change_real(win->c);
	draw(win);
	mlx_put_image_to_window
		(win->mlx_ptr, win->win_ptr, win->img.img_ptr, 0, 0);
	return (0);
}
