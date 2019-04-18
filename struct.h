/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:54:43 by bbataini          #+#    #+#             */
/*   Updated: 2018/04/23 19:39:06 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define OFFSET 100
# define CST1 8
# define CST2 8
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define BUFF_SIZE 1

typedef struct		s_tab
{
	int		xmax;
	int		ymax;
	int		y;
	int		x;
	int		z;
	int		i;
	char	**tab;
}					t_tab;

typedef struct		s_point
{
	int		xa;
	int		ya;
	int		xb;
	int		yb;
	int		x;
	int		y;
	int		c;
}					t_point;

typedef struct		s_col
{
	char	r;
	char	g;
	char	b;
}					t_col;

typedef struct		s_image
{
	void	*image;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
}					t_image;

typedef struct		s_mouss
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}					t_mouss;

typedef struct		s_pars
{
	int		fd;
	int		ret;
	char	*tmp;
	char	line[BUFF_SIZE + 1];
}					t_pars;

typedef struct		s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		wwidth;
	int		wheight;
	t_col	*color;
	int		c;
	int		offset;
	int		offsety;
	t_pars	pa;
	t_image *img;
	t_tab	t;
	t_point p;
	int		h;
	int		cst1;
	int		cst2;
	int		winzx;
	int		winzy;
	int		vue;
	t_mouss	mouss;
}					t_win;

#endif
