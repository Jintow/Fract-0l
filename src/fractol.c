/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:09:42 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/02 13:47:55 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_window(int argc, char **argv, t_win *win);

int	main(int argc, char **argv)
{
	t_win	win;

	init_window(argc, argv, &win);
	mlx_hook(win.win, 2, 1L << 0, keyboard_action, &win);
	mlx_hook(win.win, 6, 1L << 6, mouse_modif_param, &win);
	mlx_mouse_hook(win.win, mouse_param, &win);
	mlx_hook(win.win, 17, 1L << 0, gate_away, &win);
	mlx_loop(win.mlx);
}

void	init_window(int argc, char **argv, t_win *win)
{	
	win->c.re = 0;
	win->c.im = 0;
	check_option(argc, argv, win);
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, SIZE_X, SIZE_Y, TITLE);
	win->img1.img = mlx_new_image(win->mlx, SIZE_X, SIZE_Y);
	win->img2.img = mlx_new_image(win->mlx, SIZE_X, SIZE_Y);
	win->img1.addr = mlx_get_data_addr(win->img1.img, \
		&win->img1.bits_per_pixel, \
		&win->img1.line_length, &win->img1.endian);
	win->img2.addr = mlx_get_data_addr(win->img2.img, \
		&win->img2.bits_per_pixel, \
		&win->img2.line_length, &win->img2.endian);
	win->img_print = &win->img1;
	win->zoom = 1.5;
	win->mv_right = 0;
	win->mv_up = 0;
	win->nb_it_max = MAX_IT;
	win->pause_init = 1;
	init_option(win);
	init_option2(win);
}

int	gate_away(t_win	*win)
{
	mlx_destroy_image(win->mlx, win->img1.img);
	mlx_destroy_image(win->mlx, win->img2.img);
	mlx_destroy_window(win->mlx, win->win);
	free(win->pal);
	exit(0);
	return (0);
}
