/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hastid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:03:17 by hastid            #+#    #+#             */
/*   Updated: 2019/12/20 11:24:25 by hastid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fract(t_f *f)
{
	f->max.x = 2;
	f->min.x = -2;
	f->max.y = 2;
	f->min.y = -2;
	f->itr = 40;
}

static int	check_iteration(int itr, float x, float y)
{
	int		i;
	t_c		z;
	double	old_real_nbr;

	i = 0;
	z.x = 0;
	z.y = 0;
	while ((i < itr) && ((z.x * z.x + z.y * z.y) < 4))
	{
		old_real_nbr = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + x;
		z.y = (2 * old_real_nbr * z.y) + y;
		i++;
	}
	return (i);
}

void		draw_mandelbrot(t_f *f)
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
			res = check_iteration(f->itr, c.x, c.y);
			if (res != f->itr)
				f->m_d[(j * IMG_W) + i] = res * f->color;
			else
				f->m_d[(j * IMG_W) + i] = 0x000000;
			i++;
		}
		j++;
	}
}

int			mandelbrot(t_f *f)
{
	init_fract(f);
	draw_mandelbrot(f);
	return (1);
}
