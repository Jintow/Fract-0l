/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:16:26 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/02 13:08:47 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	arrow_move(int key, t_win *win);
void	modif_julia(int key, t_win *win);

int	keyboard_action(int key, t_win *win)
{
	if (key == 53)
		gate_away(win);
	else if (key == 84 || key == 88 || key == 86 || key == 91)
		modif_julia(key, win);
	else if (key >= 123 && key <= 126)
		arrow_move(key, win);
	else if (key == 49)
	{
		if (!win->pause_init)
			win->pause_init = 1;
		else
		{
			win->pause_init = 0;
			win->mv_right = 0;
			win->mv_up = 0;
			win->zoom = 1.5;
		}
	}
	else
		return (1);
	draw_frac(win);
	return (1);
}

int	mouse_param(int button, int x, int y, t_win *win)
{
	static int	it;

	if (button == SCROLL_UP && win->zoom < 200)
	{
		win->zoom *= 1.1;
		win->mv_right -= win->zoom * (x - MID_SIZE_X) / MID_SIZE_X * 0.1;
		win->mv_up -= win->zoom * (MID_SIZE_Y - y) / MID_SIZE_Y * 0.1;
		it --;
	}
	else if (button == SCROLL_DW)
	{
		win->mv_right += win->zoom * (x - MID_SIZE_X) / MID_SIZE_X * 0.1;
		win->mv_up += win->zoom * (MID_SIZE_Y - y) / MID_SIZE_Y * 0.1;
		win->zoom /= 1.1;
		it ++;
	}
	if (win->nb_it_max < 200 && it % (4 * win->nb_categ) == 0)
	{
		win->nb_it_max += it / 2;
		it = 0;
	}
	draw_frac(win);
	return (0);
}

void	arrow_move(int key, t_win *win)
{
	if (key == 125)
		win->mv_up -= 0.05 * win->zoom;
	else if (key == 126)
		win->mv_up += 0.05 * win->zoom;
	else if (key == 124)
		win->mv_right += 0.05 * win->zoom;
	else if (key == 123)
		win->mv_right += -0.05 * win->zoom;
}

void	modif_julia(int key, t_win *win)
{
	if (key == 88)
		win->c.re += 0.001;
	else if (key == 86)
		win->c.re -= 0.001;
	else if (key == 91)
		win->c.im += 0.001;
	else if (key == 84)
		win->c.im -= 0.001;
	win->c.mod = sqrt(win->c.im * win->c.im + win->c.re * win->c.re);
}

int	mouse_modif_param(int x, int y, t_win *win)
{
	if (!win->pause_init && (win->fractal == 'j' || win->fractal == 'J'))
	{
		win->c.re = ((double)x / MID_SIZE_X - 1) * win->zoom;
		win->c.im = -((double)y / MID_SIZE_Y - 1) * win->zoom;
		win->c.mod = sqrt(win->c.im * win->c.im + win->c.re * win->c.re);
		draw_frac(win);
	}
	return (0);
}
