/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:59:24 by bbataini          #+#    #+#             */
/*   Updated: 2018/04/23 20:38:26 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		parallel2(t_win *w, int x, int y)
{
	y++;
	if (y >= w->t.ymax || x >= w->t.xmax)
		return (0);
	w->p.xb = (w->offset / 2) + x * w->cst1 + (w->h * w->t.tab[y][x]);
	w->p.yb = w->offsety + y * w->cst2 + (w->h * w->t.tab[y][x] / 2);
	w->c = definecol(w->t.tab[y][x]);
	trace(&w->p, w);
	return (0);
}

void	parallel(t_win w)
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
			w.p.xa = (w.offset / 2) + x * w.cst1 + (w.h * w.t.tab[y][x]);
			w.p.ya = w.offsety + y * w.cst2 + (w.h * w.t.tab[y][x] / 2);
			if (y != w.t.ymax)
				parallel2(&w, x, y);
			w.c = definecol(w.t.tab[y][x++]);
			w.p.xb = (w.offset / 2) + x * w.cst1 + (w.h * w.t.tab[y][x]);
			w.p.yb = w.offsety + y * w.cst2 + (w.h * w.t.tab[y][x] / 2);
			if (x != w.t.xmax)
				trace(&w.p, &w);
		}
		y++;
	}
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img, 0, 0);
}
