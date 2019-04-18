/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:12:25 by bbataini          #+#    #+#             */
/*   Updated: 2018/04/23 20:35:41 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				definecol(int z)
{
	int c;

	if (z <= 0)
		c = 1;
	if (z <= -3)
		c = 0;
	if (z > 0)
	{
		c = 2;
		if (z > 5)
			c++;
		if (z > 10)
			c++;
		if (z > 20)
			c++;
	}
	return (c);
}

t_col			*init_color(void)
{
	static t_col color[8] = {
		{255, 0, 0},
		{248, 248, 121},
		{0, 255, 0},
		{79, 248, 87},
		{0, 191, 255},
		{128, 128, 128},
		{255, 255, 255}
	};

	return (color);
}

static void		pixel_put_to_img(t_win *w, int x, int y)
{
	if (x <= w->winzx - 1 && x >= 0 && y < w->winzy && y > 0)
	{
		x = x * w->img->bpp / 8;
		y = y * w->img->sizeline;
		w->img->data[x + y] = w->color[w->c].r;
		w->img->data[x + 1 + y] = w->color[w->c].g;
		w->img->data[x + 2 + y] = w->color[w->c].b;
	}
}

int				tracer(t_point *a, t_win *w)
{
	if (a->ya >= a->yb)
	{
		a->x = a->yb;
		while (a->x <= a->ya)
		{
			pixel_put_to_img(w, a->xa + ((a->xb - a->xa)
						* (a->x - a->ya)) / (a->yb - a->ya), a->x);
			a->x++;
		}
		return (0);
	}
	if (a->ya <= a->yb)
	{
		a->x = a->ya;
		while (a->x <= a->yb)
		{
			pixel_put_to_img(w, a->xb + ((a->xa - a->xb)
						* (a->x - a->yb)) / (a->ya - a->yb), a->x);
			a->x++;
		}
		return (0);
	}
	return (0);
}

void			trace(t_point *a, t_win *w)
{
	if (a->xa == a->xb)
		a->xb++;
	a->c = (a->yb - a->ya) / (a->xb - a->xa);
	if (-1 <= a->c && a->c <= 1 && a->xa <= a->xb)
	{
		a->x = a->xa;
		while (a->x <= a->xb)
			pixel_put_to_img(w, a->x, a->ya + ((a->yb - a->ya)
						* (a->x++ - a->xa)) / (a->xb - a->xa));
		return ;
	}
	if (a->xa >= a->xb && -1 <= a->c && a->c <= 1)
	{
		a->x = a->xb;
		while (a->x <= a->xa)
		{
			pixel_put_to_img(w, a->x, a->yb + ((a->ya - a->yb)
						* (a->x - a->xb)) / (a->xa - a->xb));
			a->x++;
		}
		return ;
	}
	tracer(a, w);
}
