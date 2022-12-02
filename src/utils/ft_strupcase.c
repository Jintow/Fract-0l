/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:47:03 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/30 13:24:25 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	**ft_strupcase(char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
			if (str[i][j] >= 'a' && str[i][j] <= 'z')
				str[i][j] -= 32;
	}
	return (str);
}
