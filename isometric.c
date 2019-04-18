/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:05:59 by bbataini          #+#    #+#             */
/*   Updated: 2018/04/17 21:39:13 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		trace2(t_win *w, int x, int y)
{
	y++;
	if (y >= w->t.ymax || x >= w->t.xmax)
		return (0);
	w->p.xb = w->offset + (w->cst1 * x - w->cst2 * y);
	w->p.yb = w->offsety + (w->t.tab[y][x] * w->h) + ((w->cst1 / 2) * x)
		+ ((w->cst2 / 2) * y);
	w->c = definecol(w->t.tab[y][x]);
	trace(&w->p, w);
	return (0);
}

void	isometric(t_win w)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y <= w.t.ymax - 1 || x < w.t.xmax)
	{
		x = 0;
		while (x <= w.t.xmax - 1 && y <= w.t.ymax)
		{
			w.p.xa = w.offset + (w.cst1 * x - w.cst2 * y);
			w.p.ya = w.offsety + (w.t.tab[y][x] * w.h)
				+ ((w.cst1 / 2) * x) + ((w.cst2 / 2) * y);
			if (y != w.t.ymax)
				trace2(&w, x, y);
			w.c = definecol(w.t.tab[y][x++]);
			w.p.xb = w.offset + (w.cst1 * x - w.cst2 * y);
			w.p.yb = w.offsety + (w.t.tab[y][x] * w.h) +
				((w.cst1 / 2) * x) + ((w.cst2 / 2) * y);
			if (x != w.t.xmax)
				trace(&w.p, &w);
		}
		y++;
	}
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img, 0, 0);
}
