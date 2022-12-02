/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:58:50 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/30 11:27:56 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	position_in_base(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i] != str)
		i++;
	return (i);
}

unsigned int	ft_atoi_base(char *str)
{
	unsigned int	i;
	unsigned int	nb;

	nb = 0;
	i = 0;
	while (str[i])
		nb = position_in_base(str[i++], BASE_HEX_CAP) + (nb * 16);
	return (nb);
}
