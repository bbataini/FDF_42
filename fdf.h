/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:59:32 by bbataini          #+#    #+#             */
/*   Updated: 2018/04/19 17:04:58 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "struct.h"

int			parser(char **av, t_win *w);

void		isometric(t_win w);

void		parallel(t_win w);

void		trace(t_point *a, t_win *w);

t_col		*init_color(void);

int			init_img(t_win w);

t_image		*newimg(t_win *w);

t_image		*del_image(t_win w, t_image *img);

void		clear_image(t_image *image, t_win *w);

int			definecol(int c);

int			size(t_win w);

int			windowsize(t_win *w);

void		display_text(void);

#endif
