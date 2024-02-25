/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:53:54 by mlaporte          #+#    #+#             */
/*   Updated: 2024/02/25 15:34:12 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	get_c(char *re, char *im, t_window *win)
{
	if (!win->c)
		return ;
	win->c->a = ft_atof(re);
	win->c->b = ft_atof(im);
	return ;
}

int	check_arg(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if ((*str == '.' || *str == ',') && *(str + 1))
		str++;
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (*str)
		return (1);
	return (0);
}

int	check_julia(char **argv, t_window *win)
{
	if (!(ft_strlen(argv[1]) == 1 && ft_strncmp(argv[1], "j", 1) == 0)
		&& ft_strncmp(argv[1], "julia", 5) != 0)
		return (1);
	win = init_window("Julia", JULIA, win);
	if (check_arg(argv[2]) || check_arg(argv[3]))
		return (1);
	get_c(argv[2], argv[3], win);
	return (0);
}

int	parsing(int argc, char **argv, t_window *win)
{
	if (argc == 2)
	{
		if ((ft_strlen(argv[1]) == 1 && ft_strncmp(argv[1], "m", 1) == 0)
			|| ft_strncmp(argv[1], "mandelbrot", 10) == 0)
			win = init_window("Mandelbrot", MANDELBROT, win);
		else if ((ft_strlen(argv[1]) == 1 && ft_strncmp(argv[1], "j", 1) == 0)
			|| ft_strncmp(argv[1], "julia\0", 6) == 0)
		{
			win = init_window("Julia", JULIA, win);
			get_c("0.285", "0.013", win);
		}
		else if ((ft_strlen(argv[1]) == 1 && ft_strncmp(argv[1], "s", 1) == 0)
			|| ft_strncmp(argv[1], "ship\0", 5) == 0)
			win = init_window("Burning ship", SHIP, win);
		else
			return (1);
	}
	else if (argc == 4)
	{
		if (check_julia(argv, win))
			return (1);
	}
	else
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_window	*win;

	if (argc < 2 || argc > 4)
	{
		write(2, "Wrong number of arguments.\n", 27);
		write(2, "<./fractol> <m/j/s/mandelbrot/julia/ship> (<re> <im>)\n", 54);
		return (1);
	}
	win = malloc(sizeof(t_window));
	if (!win)
		return (1);
	if (parsing(argc, argv, win))
	{
		write(2, "Incorrect arguments.\n", 21);
		write(2, "<./fractol> <m/j/s/mandelbrot/julia/ship> (<re> <im>)\n", 54);
		free(win);
		return (1);
	}
	if (init_mlx(win))
	{
		exit_mlx(win);
		return (1);
	}
	hook(win);
	return (0);
}
