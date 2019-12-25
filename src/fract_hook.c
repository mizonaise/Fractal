/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hastid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 02:53:22 by hastid            #+#    #+#             */
/*   Updated: 2019/12/21 11:06:45 by hastid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clear_and_draw(t_f *f)
{
	mlx_destroy_image(f->m_p, f->m_i);
	f->m_i = mlx_new_image(f->m_p, IMG_W, IMG_H);
	mlx_clear_window(f->m_p, f->m_w);
	if (f->id == 0)
		draw_julia(f);
	if (f->id == 1)
		draw_mandelbrot(f);
	if (f->id == 2)
		draw_burningship(f);
	mlx_put_image_to_window(f->m_p, f->m_w, f->m_i, 0, 0);
}

int		keys_kook_2(int keycode, t_f *f)
{
	double	mov;

	if (keycode > 122 && keycode < 127)
	{
		mov = 5 * fabs(f->max.x - f->min.x) / (double)IMG_W;
		if (keycode == 125 || keycode == 126)
		{
			f->min.y += (keycode == 125) ? -mov : mov;
			f->max.y += (keycode == 125) ? -mov : mov;
		}
		else
		{
			f->min.x += (keycode == 123) ? -mov : mov;
			f->max.x += (keycode == 123) ? -mov : mov;
		}
		clear_and_draw(f);
	}
	return (0);
}

int		keys_hook(int keycode, void *param)
{
	t_f	*f;

	f = param;
	if (keycode == 49)
		f->p = !f->p;
	if (keycode == 8 || keycode == 69 || keycode == 78)
	{
		if (keycode == 8)
			f->color += 500;
		else
			f->itr += (keycode == 78 && f->itr > 10) ? -10 : 10;
		clear_and_draw(f);
	}
	if (keycode == 53)
	{
		mlx_destroy_image(f->m_p, f->m_i);
		mlx_clear_window(f->m_p, f->m_w);
		mlx_destroy_window(f->m_p, f->m_w);
		exit(0);
	}
	return (keys_kook_2(keycode, f));
}

void	zoom(int x, int y, t_f *f, double z)
{
	t_c m;

	m.x = f->min.x + ((double)x * (f->max.x - f->min.x)) / (double)IMG_W;
	m.y = f->min.y + ((double)y * (f->max.y - f->min.y)) / (double)IMG_H;
	f->min.x = m.x + (f->min.x - m.x) * z;
	f->max.x = m.x + (f->max.x - m.x) * z;
	f->min.y = m.y + (f->min.y - m.y) * z;
	f->max.y = m.y + (f->max.y - m.y) * z;
}

int		mouse_hook(int m, int x, int y, t_f *f)
{
	if (m == 4)
		zoom(x, y, f, 0.9 / 1.05);
	if (m == 5 && fabs(f->max.x - f->min.x) <= 5)
		zoom(x, y, f, 1.05 / 0.9);
	clear_and_draw(f);
	return (0);
}
