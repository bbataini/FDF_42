/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:32:49 by bbataini          #+#    #+#             */
/*   Updated: 2018/04/23 19:57:22 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_text(void)
{
	ft_putstr("\n     FDF de bbataini \n\n\n");
	ft_putstr("mode d emploi :\n");
	ft_putstr("changement de vue : 'F'\n");
	ft_putstr("incrementer / decrementer la hauteur : '+' / '-'\n");
	ft_putstr("zoom            : 'Q' / 'E'\n");
	ft_putstr("zoom horizontal : '1' / '2'\n");
	ft_putstr("zoom vertical   : '3' / '4'\n");
	ft_putstr("deplacement avec les fleches ou WSAD\n");
}
