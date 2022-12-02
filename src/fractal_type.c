/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:42:56 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/02 13:04:43 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	make_julia(double x, double y, t_win *win)
{
	t_cmplx			nb;
	int				i;

	nb.re = (x - MID_SIZE_X) * win->zoom / (MID_SIZE_X) + win->mv_right;
	nb.im = (MID_SIZE_Y - y) * win->zoom / (MID_SIZE_Y) + win->mv_up;
	nb.sum1 = 0;
	i = 0;
	while (i++ < win->nb_it_max)
	{
		nb.mod = nb.re * nb.re + nb.im * nb.im;
		if (nb.mod > 4)
			return (smooth_color(i - 1, nb.mod, win));
		nb.re_temp = nb.re;
		nb.im_temp = nb.im;
		nb.re = nb.re * nb.re - nb.im * nb.im + win->c.re;
		nb.im = 2 * nb.re_temp * nb.im + win->c.im;
	}
	return (0x00000001);
}

unsigned int	make_burning_ship(double x, double y, t_win *win)
{
	t_cmplx			nb;
	int				i;

	nb.re = win->c.re;
	nb.im = win->c.im;
	i = 0;
	while (i++ < win->nb_it_max)
	{
		nb.mod = nb.re * nb.re + nb.im * nb.im;
		if (nb.mod > 4)
			return (smooth_color(i - 1, nb.mod, win));
		nb.re_temp = fabs(nb.re);
		nb.im_temp = fabs(nb.im);
		nb.re = nb.re_temp * nb.re_temp - nb.im_temp * nb.im_temp + \
		(x - MID_SIZE_X) * win->zoom / (MID_SIZE_X) + win->mv_right;
		nb.im = 2 * nb.re_temp * nb.im_temp + \
		(MID_SIZE_Y - y) * win->zoom / (MID_SIZE_Y) + win->mv_up;
	}
	return (0x00000001);
}

unsigned int	make_mandelbrot(double x, double y, t_win *win)
{
	t_cmplx			nb;
	int				i;

	nb.re = win->c.re;
	nb.im = win->c.im;
	i = 0;
	while (i++ < win->nb_it_max)
	{
		nb.mod = nb.re * nb.re + nb.im * nb.im;
		if (nb.mod > 4)
			return (smooth_color(i - 1, nb.mod, win));
		nb.re_temp = nb.re;
		nb.im_temp = nb.im;
		nb.re = nb.re * nb.re - nb.im * nb.im + \
		(x - MID_SIZE_X) * win->zoom / (MID_SIZE_X) + win->mv_right;
		nb.im = 2 * nb.re_temp * nb.im + \
		(MID_SIZE_Y - y) * win->zoom / (MID_SIZE_Y) + win->mv_up;
	}
	return (0x00000001);
}

unsigned int	make_julia3(double x, double y, t_win *win)
{
	t_cmplx			nb;
	int				i;

	nb.re = (x - MID_SIZE_X) * win->zoom / (MID_SIZE_X) + win->mv_right;
	nb.im = (MID_SIZE_Y - y) * win->zoom / (MID_SIZE_Y) + win->mv_up;
	nb.sum1 = 0;
	i = 0;
	while (i++ < win->nb_it_max)
	{
		nb.mod = nb.re * nb.re + nb.im * nb.im;
		if (nb.mod > 4)
			return (smooth_color(i - 1, nb.mod, win));
		nb.re_temp = nb.re;
		nb.im_temp = nb.im;
		nb.re = nb.re * nb.re * nb.re - 3 * nb.im * nb.im * nb.re + win->c.re;
		nb.im = -nb.im * nb.im * nb.im + 3 * nb.re_temp * nb.re_temp * nb.im \
			+ win->c.im;
	}
	return (0x00000001);
}
