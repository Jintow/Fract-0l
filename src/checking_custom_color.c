/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_custom_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:58:25 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/02 11:21:24 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		contain(char *str, char c);
int		valid_format(char *str);
void	check_format(char *str);

void	check_custom_color(char **color)
{
	int	i;

	if (!color[0])
	{
		ft_printf("NO COLOR ARGUMENT given, give at leat one.\n");
		ft_printf("Colors must be in hex format (length = 8) ex: \"007C00FF\"\n");
		exit(0);
	}
	i = 0;
	while (color[i])
		check_format(color[i++]);
}

void	check_format(char *str)
{
	if (ft_strlen(str) != 8)
	{
		ft_printf("BAD COLOR ARGUMENT: %s\n", str);
		ft_printf("Colors must be in hex format (length = 8) ex: \"007C00FF\"\n");
		exit(0);
	}
	if (!valid_format(str))
	{
		ft_printf("BAD COLOR ARGUMENT : %s\n", str);
		ft_printf("Colors must be in hex format ex: \"007C00FF\"\n");
		exit(0);
	}
}

int	valid_format(char *str)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (!contain(BASE_HEX_CAP, str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	contain(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return (1);
	}
	return (0);
}
