/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colouring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:21:03 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/02 10:07:48 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	smoothering_color(float nb_it, \
	int color, int categ, t_color *pal)
{
	t_color			clr;

	clr.rgba.tra = pal[color].rgba.tra + \
	((pal[color + 1].rgba.tra - pal[color].rgba.tra) * \
	((nb_it - categ * color) / categ));
	clr.rgba.red = pal[color].rgba.red + \
	((pal[color + 1].rgba.red - pal[color].rgba.red) * \
	((nb_it - categ * color) / categ));
	clr.rgba.gre = pal[color].rgba.gre + \
	((pal[color + 1].rgba.gre - pal[color].rgba.gre) * \
	((nb_it - categ * color) / categ));
	clr.rgba.blu = pal[color].rgba.blu + \
	((pal[color + 1].rgba.blu - pal[color].rgba.blu) * \
	((nb_it - categ * color) / categ));
	return (clr.col);
}

unsigned int	smooth_color(int it, float mod, t_win *win)
{
	float	fact;
	int		color;
	int		categ;

	fact = 1 + ((log(log(2)) - log((0.5 * log(mod)))) / log(2));
	if (fact > 0.9999)
		fact = 0.9999;
	if (fact < 0)
		fact = 0;
	fact += it;
	categ = (win->nb_it_max / win->nb_categ);
	if (!categ)
		categ = 1;
	color = it / categ;
	if (color < 0)
		color = 0;
	return (smoothering_color(fact, color, categ, win->pal));
}
