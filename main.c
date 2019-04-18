/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:30:17 by bbataini          #+#    #+#             */
/*   Updated: 2018/04/23 21:09:24 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key2(int key, t_win *w)
{
	if (key == 14)
	{
		w->cst1 = w->cst1 + 1;
		w->cst2 = w->cst2 + 1;
		return (0);
	}
	if (key == 12)
	{
		w->cst2 = w->cst2 - 1;
		w->cst1 = w->cst1 - 1;
		return (0);
	}
	if (key == 27 || key == 78)
		w->h = w->h - 1;
	if (key == 18)
		w->cst1 = w->cst1 + 1;
	if (key == 19)
		w->cst1 = w->cst1 - 1;
	if (key == 20)
		w->cst2 = w->cst2 - 1;
	if (key == 21)
		w->cst2 = w->cst2 + 1;
	return (0);
}

int		deal_key(int key, t_win *w)
{
	if (key == 53)
		exit(42);
	if (key == 126 || key == 13)
		w->offsety = w->offsety - 10;
	if (key == 125 || key == 1)
		w->offsety = w->offsety + 10;
	if (key == 123 || key == 0)
		w->offset = w->offset - 10;
	if (key == 124 || key == 2)
		w->offset = w->offset + 10;
	if (key == 24 || key == 69)
		w->h = w->h + 1;
	deal_key2(key, w);
	if (key == 3 && w->vue == 1)
		w->vue--;
	else if (key == 3)
		w->vue++;
	w->img = newimg(w);
	if (w->vue == 1)
		parallel(*w);
	if (w->vue == 0)
		isometric(*w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img->image, 0, 0);
	return (0);
}

int		init(t_win *w)
{
	w->t.i = 0;
	w->t.xmax = 0;
	w->t.ymax = 0;
	w->cst1 = CST1 + 0;
	w->cst2 = CST2 + 0;
	w->h = -1;
	w->offsety = OFFSET;
	return (0);
}

int		gere_mouse(int button, int x, int y, t_win *w)
{
	if (w->p.xa == 0)
	{
		w->p.xa = x;
		w->p.ya = y;
	}
	else if (w->p.xb == 0)
	{
		w->p.xb = x;
		w->p.yb = y;
		w->c = 1;
		trace(&w->p, w);
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img->image, 0, 0);
		return (0);
	}
	else
	{
		w->p.xb = 0;
		w->p.xa = 0;
		w->p.yb = 0;
		w->p.ya = 0;
		gere_mouse(0, x, y, w);
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img->image, 0, 0);
	return (button);
}

int		main(int ac, char **av)
{
	t_win		w;

	if (ac != 2)
	{
		ft_putstr("fichier txt svp\n");
		return (0);
	}
	w.vue = 0;
	display_text();
	init(&w);
	parser(av, &w);
	windowsize(&w);
	w.mlx_ptr = mlx_init();
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.winzx, w.winzy, "mlx 42");
	w.color = init_color();
	w.img = newimg(&w);
	isometric(w);
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img->image, 0, 0);
	mlx_mouse_hook(w.win_ptr, gere_mouse, &w);
	mlx_key_hook(w.win_ptr, deal_key, &w);
	mlx_loop(w.mlx_ptr);
	return (0);
}
