/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newimg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:36:20 by bbataini          #+#    #+#             */
/*   Updated: 2018/04/17 19:45:23 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_image		*newimg(t_win *w)
{
	t_image		*img;

	if ((img = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	img->image = mlx_new_image(w->mlx_ptr, w->winzx, w->winzy);
	img->data = mlx_get_data_addr(img->image,
	&img->bpp, &img->sizeline, &img->endian);
	return (img);
}
