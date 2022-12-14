/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:55:05 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/30 17:37:01 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	make_str(char *str, float nb)
{
	int	i;
	int	j;
	int	nbr;

	i = 0;
	j = 0;
	while (i++ < 3)
	{
		nbr = nb;
		str[j++] = nbr + '0';
		nb = (nb - nbr) * 10;
	}
	str[j] = 0;
}

char	*ft_itoa(double nb)
{
	char	*str;
	int		j;
	int		nbr;

	str = malloc(sizeof(char) * 10);
	if (!str)
		return (NULL);
	j = 0;
	if (nb < 0)
	{
		str[j++] = '-';
		nb = -nb;
	}
	nbr = nb;
	str[j++] = nbr + '0';
	nb = (nb - nbr) * 10;
	str[j++] = '.';
	make_str(&str[j], nb);
	return (str);
}
