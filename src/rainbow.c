/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:14:08 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/30 15:40:45 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	*make_rainbow(char **str)
{
	t_color	*rainbow;

	(void)str;
	rainbow = malloc(sizeof(t_color) * 7);
	if (!rainbow)
		exit(0);
	rainbow[0].col = 0x00311B92;
	rainbow[1].col = 0x0029B6F6;
	rainbow[2].col = 0x0076FF03;
	rainbow[3].col = 0x00FFEB3B;
	rainbow[4].col = 0x00FFA726;
	rainbow[5].col = 0x00DD2C00;
	rainbow[6].col = 0;
	return (rainbow);
}

t_color	*make_sunset(char **str)
{
	t_color	*sunset;

	(void)str;
	sunset = malloc(sizeof(t_color) * 5);
	if (!sunset)
		exit(0);
	sunset[0].col = 0x0001579B;
	sunset[1].col = 0x00E1F5FE;
	sunset[2].col = 0x00FDD835;
	sunset[3].col = 0x00BF360C;
	sunset[4].col = 0;
	return (sunset);
}

t_color	*make_matrix_virus(char **str)
{
	t_color	*matrix;

	(void)str;
	matrix = malloc(sizeof(t_color) * 5);
	if (!matrix)
		exit(0);
	matrix[2].col = 0x00FF360C;
	matrix[0].col = 0x008BC34A;
	matrix[1].col = 0x000D47A1;
	matrix[3].col = 0x001B5E20;
	matrix[4].col = 0;
	return (matrix);
}

t_color	*make_custom(char **str)
{
	t_color	*custom;
	int		i;
	int		len;

	i = 0;
	while (str[i])
		i++;
	len = i;
	custom = malloc(sizeof(t_color) * (len + 1));
	if (!custom)
		exit(0);
	i = 0;
	while (str[i])
	{
		custom[i].col = ft_atoi_base(str[i]);
		i++;
	}
	custom[i].col = 0;
	return (custom);
}
