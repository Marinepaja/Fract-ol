/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:57:26 by mlaporte          #+#    #+#             */
/*   Updated: 2024/02/25 15:36:05 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define SHIP 3
# define JULIA 2
# define MANDELBROT 1
# define K_C 99
# define K_I 105
# define K_R 114
# define K_ESC 65307
# define K_UP  65362
# define K_DOWN 65364
# define K_RIGHT 65363
# define K_LEFT 65361
# define M_UP 61
# define M_DOWN 45
# define WIDTH 1200
# define HEIGHT	800
# define MLX_ERROR 1
# define RAND_MAX 0xFFFFFF
# include <unistd.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <X11/X.h>
# include <stdio.h>
# include <math.h>

typedef struct s_complex
{
	float	a;
	float	b;
	float	mod;

}	t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*add;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*title;
	float		zoom;
	t_image		img;
	t_complex	*offset;
	t_complex	*c;
	int			set;
	int			color;
}	t_window;

t_complex	add_z(t_complex z1, t_complex z2);
t_complex	multiply_z(t_complex z1, t_complex z2);
t_window	*init_window(char *title, int set, t_window *win);
float		burning_ship(t_complex c);
float		mandelbrot(t_complex c);
int			handle_cross(t_window *window);
int			deal_key(int key, t_window *win);
void		img_pix_put(t_image *img, int x, int y, int color);
float		julia(t_complex z, t_complex c);
int			init_mlx(t_window *win);
void		exit_mlx(t_window *win);
void		draw_mandel(t_window *win);
void		draw_julia(t_window *win, t_complex *c);
void		draw_ship(t_window *win);
float		ft_atof(char *num);
void		draw(t_window *win);
void		hook(t_window *win);
int			mouse_events(int keysym, int x, int y, t_window *win);

#endif