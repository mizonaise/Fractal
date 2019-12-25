/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hastid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:28:28 by hastid            #+#    #+#             */
/*   Updated: 2019/12/21 11:10:01 by hastid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fract(t_f *f)
{
	f->m.x = 0.285;
	f->m.y = 0.01;
	f->max.x = 2;
	f->min.x = -2;
	f->max.y = 2;
	f->min.y = -2;
	f->itr = 40;
	f->p = 1;
}

static int	check_iteration(int itr, float x, float y, t_c c)
{
	int		i;
	t_c		z;
	double	old_real_nbr;

	i = 0;
	z.x = x;
	z.y = y;
	while ((i < itr) && ((z.x * z.x + z.y * z.y) < 4))
	{
		old_real_nbr = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = (2 * old_real_nbr * z.y) + c.y;
		i++;
	}
	return (i);
}

void		draw_julia(t_f *f)
{
	int i;
	int j;
	int res;
	t_c	c;

	j = 0;
	while (j < IMG_H)
	{
		i = 0;
		c.y = f->min.y + (j * (f->max.y - f->min.y)) / (double)IMG_H;
		while (i < IMG_W)
		{
			c.x = f->min.x + (i * (f->max.x - f->min.x)) / (double)IMG_W;
			res = check_iteration(f->itr, c.x, c.y, f->m);
			if (res != f->itr)
				f->m_d[(j * IMG_W) + i] = res * f->color;
			else
				f->m_d[(j * IMG_W) + i] = 0x000000;
			i++;
		}
		j++;
	}
}

int			julia(t_f *f)
{
	init_fract(f);
	draw_julia(f);
	return (1);
}

int			mouse_move(int x, int y, t_f *f)
{
	if (f->id == 0 && f->p)
	{
		f->m.x = f->min.x + ((double)x * (f->max.x - f->min.x)) / (double)IMG_W;
		f->m.y = f->min.y + ((double)y * (f->max.y - f->min.y)) / (double)IMG_H;
		clear_and_draw(f);
	}
	return (0);
}
