/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:11:10 by mlaporte          #+#    #+#             */
/*   Updated: 2024/02/25 15:29:29 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw(t_window *win);

int	handle_cross(t_window *win)
{
	exit_mlx(win);
	exit (0);
}

int	mouse_events(int keysym, int x, int y, t_window *win)
{
	if (keysym == Button1 || keysym == Button4)
	{
		win->zoom *= 1.2;
		win->offset->a += (((float)x / WIDTH) - 0.5) / (0.5 * win->zoom);
		win->offset->b += (((float)y / HEIGHT) - 0.5) / (0.5 * win->zoom);
	}
	else if (keysym == Button3 || keysym == Button5)
	{
		win->zoom *= 0.8;
		win->offset->a += (((float)x / WIDTH) - 0.5) / (0.5 * win->zoom);
		win->offset->b += (((float)y / HEIGHT) - 0.5) / (0.5 * win->zoom);
	}
	draw(win);
	mlx_put_image_to_window
		(win->mlx_ptr, win->win_ptr, win->img.img_ptr, 0, 0);
	return (0);
}

t_window	*init_window(char *title, int set, t_window	*win)
{
	if (!win)
		return (0x0);
	ft_bzero(&(win->img), sizeof(t_image));
	win->win_ptr = 0x0;
	win->mlx_ptr = 0x0;
	win->title = title;
	win->zoom = 1.0;
	win->set = set;
	win->color = 0x001515;
	win->offset = malloc(sizeof(t_complex));
	if (!win->offset)
		return (0x0);
	win->offset->a = 0;
	win->offset->b = 0;
	win->c = malloc(sizeof(t_complex));
	if (!win->c)
		return (0x0);
	return (win);
}

void	img_pix_put(t_image *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->add + (y * img->size_line + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
