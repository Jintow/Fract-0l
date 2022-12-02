 unsigned int	smoothering_color(float fact, \
	int color, t_color *pal)
{
	t_color			clr;

	
	clr.rgba.tra = pal[color].rgba.tra + \
	((pal[color + 1].rgba.tra - pal[color].rgba.tra) * \
	fact);
	clr.rgba.red = pal[color].rgba.red + \
	((pal[color + 1].rgba.red - pal[color].rgba.red) * \
	fact);
	clr.rgba.gre = pal[color].rgba.gre + \
	((pal[color + 1].rgba.gre - pal[color].rgba.gre) * \
	fact);
	clr.rgba.blu = pal[color].rgba.blu + \
	((pal[color + 1].rgba.blu - pal[color].rgba.blu) * \
	fact);
	return (clr.col);
}

unsigned int	smooth_color(int it, float mod, t_win *win)
{
	float	fact;
	int		color;

	fact = 1 + ((log(log(2)) - log((0.5 * log(mod)))) / log(2));
	if (fact > 0.9999)
		fact = 0.9999;
	if (fact < 0)
		fact = 0;
	color = it % (win->nb_categ - 1);
	return (smoothering_color(fact, color, win->pal));
}

void	tia_calculator(int i, t_cmplx *zn, t_win *win)
{
	float	mn;
	float	mn2;
	t_cmplx	zb;

	if (i < win->nb_it_max - 1)
	{
		zn->sum2 = zn->sum1;
		zb.re = zn->re - win->c.re;
		zb.im = zn->im - win->c.im;
		zb.mod = sqrt(zb.im * zb.im + zb.re * zb.re);
		mn = zb.mod - win->c.mod;
		//dprintf(1, "%f %f   ", zb.mod, win->c.mod);
		if (mn < 0)
			mn = -mn;
		mn2 = (zb.mod + win->c.mod);
		//dprintf(1, "%f %f   ", mn2, mn);
		zn->sum1 += (sqrt(zn->re * zn->re + zn->im * zn->im) - mn) / (mn2 - mn);
		if (zn->sum1 < 0)
			dprintf(1, "%f ", zn->sum1);
	}
}

unsigned int	tia_colouring(int it, t_cmplx *zn, t_win *win)
{
	float	fact;
	t_color	clr;
	t_color	*pal;
	int		color;

	if (it == 1)
		return (0);
	zn->sum1 = zn->sum1 / (float)it;
	zn->sum2 = zn->sum2 / ((float)it - 1.0);
	fact = (1 + ((log(log(800000)) - log((0.5 * log(zn->mod)))) / log(2)));
	fact *= (zn->sum1 - zn->sum2);
	fact += zn->sum2;
	fact = fact - (float)floor(fact);
	//fact = fract(fact);
	// if (fact > 1)
	//dprintf(1, "%f %i   ", fact, it);
	color = it / (win->nb_it_max / win->nb_categ);
	pal = win->pal;
	clr.rgba.tra = pal[color].rgba.tra + \
	((pal[color + 1].rgba.tra - pal[color].rgba.tra) * \
	fact);
	clr.rgba.red = pal[color].rgba.red + \
	((pal[color + 1].rgba.red - pal[color].rgba.red) * \
	fact);
	clr.rgba.gre = pal[color].rgba.gre + \
	((pal[color + 1].rgba.gre - pal[color].rgba.gre) * \
	fact);
	clr.rgba.blu = pal[color].rgba.blu + \
	((pal[color + 1].rgba.blu - pal[color].rgba.blu) * \
	fact);
	return (clr.col);

unsigned int	make_julia(double x, double y, t_win *win)
{
	t_cmplx			nb;
	int				i;

	nb.re = (x - MID_SIZE_X) * win->zoom / (MID_SIZE_X) + win->mv_right;
	nb.im = (y - MID_SIZE_Y) * win->zoom / (MID_SIZE_Y) + win->mv_up;
	nb.sum1 = 0;
	i = 0;
	while (i++ < win->nb_it_max)
	{
		nb.mod = nb.re * nb.re + nb.im * nb.im;
		if (nb.mod > 160000000000)
			return (tia_colouring(i - 1, &nb, win));
		nb.re_temp = nb.re;
		nb.im_temp = nb.im;
		nb.re = nb.re * nb.re - nb.im * nb.im + win->c.re;
		nb.im = 2 * nb.re_temp * nb.im + win->c.im;
		tia_calculator(i - 1, &nb, win);
	}
	return (0x00000001);
}