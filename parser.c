/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:33:46 by bbataini          #+#    #+#             */
/*   Updated: 2018/04/19 14:46:41 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		putptab(t_tab t, char *stk, int i)
{
	int z;

	z = ft_atoi(&stk[i]);
	t.tab[t.y][t.x] = z;
	if (z < 0)
	{
		i++;
		z = -z;
	}
	while (z > 9)
	{
		z = z / 10;
		i++;
	}
	i++;
	return (i);
}

int		putotab(t_tab t, char *stk)
{
	int	i;

	i = 0;
	t.y = 0;
	t.x = 0;
	while (stk[i])
	{
		if (stk[i] == '\n')
		{
			t.y++;
			t.xmax = t.x;
			t.x = 0;
			i++;
		}
		if (stk[i] == ' ')
			i++;
		else
		{
			if (stk[i] != '-' && (stk[i] < '0' || stk[i] > '9'))
				return (t.xmax);
			i = putptab(t, stk, i);
			t.x++;
		}
	}
	return (t.xmax);
}

void	youri(char *stk, t_win *w)
{
	while (stk[w->t.i])
	{
		if (stk[w->t.i] == '\n')
		{
			w->t.ymax++;
			w->t.i++;
		}
		if (stk[w->t.i] == '-' || (stk[w->t.i] >= '0' && stk[w->t.i] <= '9'))
		{
			w->t.z = ft_atoi(&stk[w->t.i]);
			w->t.xmax++;
			w->t.i++;
		}
		if (stk[w->t.i] == ' ')
			w->t.i++;
		if (w->t.z < 0 && w->t.i < (w->t.i == (w->t.i + 1)))
			w->t.z = -w->t.z;
		if (w->t.z > 9 && w->t.i < (w->t.i == (w->t.i + 1)))
			w->t.z = w->t.z / 10;
	}
	w->t.i = 0;
	w->t.tab = (char **)malloc(sizeof(char *) * w->t.ymax + 1);
	while (w->t.i <= w->t.ymax)
		w->t.tab[w->t.i++] = (char *)malloc(sizeof(char ) * w->t.xmax + 1);
	w->t.xmax = putotab(w->t, stk);
}

int		parser(char **av, t_win *w)
{
	char	*stk;

	w->pa.fd = open(av[1], O_RDONLY);
	if (w->pa.fd < 0 || BUFF_SIZE <= 0 || read(w->pa.fd, w->pa.line, 0) < 0)
	{
		ft_putstr("petit probleme de lecture :(\n");
		exit(42);
	}
	stk = NULL;
	while ((w->pa.ret = read(w->pa.fd, w->pa.line, BUFF_SIZE)))
	{
		w->pa.line[w->pa.ret] = '\0';
		if (!stk)
		{
			if (!(stk = ft_strdup(w->pa.line)))
				return (0);
		}
		else if (!(stk = ft_strjoin(stk, w->pa.line)))
			return (0);
	}
	if (stk == '\0')
		return (0);
	youri(stk, w);
	free(stk);
	return (0);
}
