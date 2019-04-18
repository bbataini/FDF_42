/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:13:49 by bbataini          #+#    #+#             */
/*   Updated: 2018/04/17 21:51:35 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		windowsize(t_win *w)
{
	if (w->t.ymax <= 30 || w->t.xmax <= 30)
	{
		w->winzy = 800;
		w->winzx = 800;
		w->offset = 350;
	}
	if (w->t.ymax > 30 || w->t.xmax > 30)
	{
		w->winzy = 1000;
		w->winzx = 1500;
		w->offset = 500;
	}
	if (w->t.ymax > 80 || w->t.xmax > 80)
	{
		w->winzy = 1600;
		w->winzx = 2000;
		w->offset = 800;
	}
	return (0);
}
