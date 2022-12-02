/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:24:29 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/02 13:10:51 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_option(t_win *win)
{
	if (win->fractal == 'j')
	{
		win->fract = &make_julia;
		win->info.mode = "JULIA";
	}
	else if (win->fractal == 'm')
	{
		win->mv_right = -0.75;
		win->fract = &make_mandelbrot;
		win->info.mode = "MANDELBROT";
	}
	else if (win->fractal == 'b')
	{
		win->mv_up = -0.5;
		win->mv_right = -0.4;
		win->fract = &make_burning_ship;
		win->info.mode = "BURNING SHIP";
	}
	else if (win->fractal == 'J')
	{	
		win->fract = &make_julia3;
		win->info.mode = "JULIA CUBED";
	}
}

int	how_many(t_color *pal)
{
	int	i;

	i = 0;
	while (pal[i].col)
		i++;
	return (i);
}

void	init_option2(t_win *win)
{
	if (win->color == 'r')
	{
		win->make = &make_rainbow;
		win->info.color_palet = "Rainbow";
	}
	else if (win->color == 's')
	{
		win->make = &make_sunset;
		win->info.color_palet = "Sunset";
	}
	else if (win->color == 'm')
	{
		win->make = &make_matrix_virus;
		win->info.color_palet = "M@tr1X_V1ruS";
	}
	else if (win->color == 'c')
	{
		win->make = &make_custom;
		win->info.color_palet = "Custom";
	}
	win->pal = (*win->make)(win->argv_col);
	win->nb_categ = how_many(win->pal);
}
