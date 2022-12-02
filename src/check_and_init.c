/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:04:10 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/02 14:33:06 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_init_value(char **argv, t_win *win);
void	check_option2(char **argv, t_win *win);

void	check_option(int argc, char **argv, t_win *win)
{
	if (argc < 2)
	{
		ft_printf(WRG_NB_ARG);
		exit(0);
	}
	else if (ft_strcmp(argv[1], "-j") && ft_strcmp(argv[1], "-m") && \
		ft_strcmp(argv[1], "-b") && ft_strcmp(argv[1], "-J3"))
	{
		ft_printf(WRG_FRAC);
		exit(0);
	}
	win->fractal = argv[1][1];
	if (win->fractal == 'J' || win->fractal == 'j')
	{
		check_init_value(&argv[2], win);
		check_option2(&argv[4], win);
	}
	else
		check_option2(&argv[2], win);
	ft_printf(WELCOME);
}

void	check_option2(char **argv, t_win *win)
{
	if (!argv[0] || (ft_strcmp(argv[0], "-s") && ft_strcmp(argv[0], "-r") && \
		ft_strcmp(argv[0], "-m") && ft_strcmp(argv[0], "-c")))
	{
		ft_printf(WRG_COLOR);
		exit(0);
	}
	win->color = argv[0][1];
	if (win->color == 'c')
		check_custom_color(ft_strupcase(&argv[1]));
	win->argv_col = &argv[1];
}

int	check_floor_value(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] > '1' || str[i] < '0')
		return (0);
	i++;
	if (!str[i])
		return (1);
	if (str[i++] != '.')
		return (0);
	while (str[i])
	{
		if (!contain(BASE_DEC, str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_init_value(char **argv, t_win *win)
{
	if (!argv[0] || !argv[1])
	{
		ft_printf(NO_VALUE);
		exit(0);
	}
	else if (!check_floor_value(argv[0]) || !check_floor_value(argv[1]))
	{
		ft_printf(BAD_VALUE);
		exit(0);
	}
	win->c.re = ft_atof(argv[0]);
	win->c.im = ft_atof(argv[1]);
}
