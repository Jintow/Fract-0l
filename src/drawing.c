/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:56:14 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/02 13:21:38 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	swap_img(t_win *win);
void	display_info(t_win *win);
void	img_mlx_pixel_put(t_data *data, int x, int y, int color);

void	draw_frac(t_win *win)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= SIZE_X)
	{
		j = -1;
		while (++j <= SIZE_Y)
			img_mlx_pixel_put(win->img_print, i, j, (*win->fract)(i, j, win));
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img_print->img, 0, 0);
	if (win->zoom < 8)
		display_info(win);
	swap_img(win);
}

void	display_info(t_win *win)
{
	win->info.c_re = ft_itoa(win->c.re);
	win->info.c_im = ft_itoa(win->c.im);
	mlx_string_put(win->mlx, win->win, 0, 30, 0x000000, "Re (c)  : ");
	mlx_string_put(win->mlx, win->win, 0, 40, 0x000000, "Im (c)  : ");
	if (win->info.c_re && win->info.c_im)
	{
		mlx_string_put(win->mlx, win->win, 70, 30, 0x000000, win->info.c_re);
		mlx_string_put(win->mlx, win->win, 70, 40, 0x000000, win->info.c_im);
		free(win->info.c_im);
		free(win->info.c_re);
	}
	mlx_string_put(win->mlx, win->win, 0, 10, 0x000000, "Mode    : ");
	mlx_string_put(win->mlx, win->win, 70, 10, 0x000000, win->info.mode);
	mlx_string_put(win->mlx, win->win, 0, 20, 0x000000, "Colours : ");
	mlx_string_put(win->mlx, win->win, 70, 20, 0x000000, win->info.color_palet);
}

void	img_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	swap_img(t_win *win)
{
	if (win->img_print == &win->img1)
		win->img_print = &win->img2;
	else if (win->img_print == &win->img2)
		win->img_print = &win->img1;
}
