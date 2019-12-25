/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hastid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 00:10:58 by hastid            #+#    #+#             */
/*   Updated: 2019/12/21 11:07:18 by hastid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define IMG_W 500
# define IMG_H 500

typedef struct	s_c
{
	double	x;
	double	y;
}				t_c;

typedef struct	s_f
{
	int		id;
	int		color;
	void	*m_p;
	void	*m_w;
	void	*m_i;
	int		*m_d;
	t_c		c;
	t_c		m;
	t_c		min;
	t_c		max;
	int		b;
	int		s;
	int		e;
	int		p;
	int		itr;
}				t_f;

int				julia(t_f *f);
int				mandelbrot(t_f *f);
int				burningship(t_f *f);
void			draw_julia(t_f *f);
void			draw_mandelbrot(t_f *f);
void			draw_burningship(t_f *f);
void			clear_and_draw(t_f *f);
int				keys_hook(int keycode, void *param);
int				mouse_hook(int events, int x, int y, t_f *f);
int				mouse_move(int x, int y, t_f *f);

#endif
