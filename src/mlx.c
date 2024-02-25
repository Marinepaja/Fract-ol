/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:11:35 by mlaporte          #+#    #+#             */
/*   Updated: 2024/02/25 15:34:21 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	init_mlx(t_window *win)
{
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		return (1);
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, win->title);
	if (!win->win_ptr)
	{
		free(win->mlx_ptr);
		return (1);
	}
	win->img.img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	if (!win->img.img_ptr)
		return (1);
	win->img.add = mlx_get_data_addr(win->img.img_ptr, &(win->img.bpp),
			&(win->img.size_line), &(win->img.endian));
	if (!win->img.add)
		return (1);
	return (0);
}

void	hook(t_window *win)
{
	draw(win);
	mlx_put_image_to_window
		(win->mlx_ptr, win->win_ptr, win->img.img_ptr, 0, 0);
	mlx_key_hook(win->win_ptr, &deal_key, win);
	mlx_mouse_hook(win->win_ptr, &mouse_events, win);
	mlx_hook(win->win_ptr, DestroyNotify, 0, &handle_cross, win);
	mlx_loop(win->mlx_ptr);
	exit_mlx(win);
}

void	exit_mlx(t_window *win)
{
	if (!win)
		return ;
	if (!win->mlx_ptr)
		return (free(win));
	mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_display(win->mlx_ptr);
	if (win->c)
		free(win->c);
	free(win->mlx_ptr);
	if (win->offset)
		free(win->offset);
	free(win);
	win = NULL;
	exit(0);
}
