/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hastid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 00:10:19 by hastid            #+#    #+#             */
/*   Updated: 2019/12/21 11:16:57 by hastid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_putstr("\033[0;31m");
	ft_putendl("/**********************************************/");
	ft_putendl("/*  Usage : ./fractol                         */");
	ft_putendl("/*                                            */");
	ft_putstr("/*               ");
	ft_putstr("\033[1;33m");
	ft_putstr("--> Julia");
	ft_putstr("\033[0;31m");
	ft_putendl("    	              */");
	ft_putendl("/*                                            */");
	ft_putstr("/*               ");
	ft_putstr("\033[1;33m");
	ft_putstr("--> Mandelbrot");
	ft_putstr("\033[0;31m");
	ft_putendl("    	      */");
	ft_putendl("/*                                            */");
	ft_putstr("/*               ");
	ft_putstr("\033[1;33m");
	ft_putstr("--> Burningship");
	ft_putstr("\033[0;31m");
	ft_putendl("              */");
	ft_putendl("/*                                            */");
	ft_putendl("/**********************************************/");
	ft_putstr("\033[0m");
}

int		fractol(int id)
{
	t_f	f;

	f.id = id;
	f.color = 0xf86868;
	f.m_p = mlx_init();
	f.m_w = mlx_new_window(f.m_p, IMG_W, IMG_H, "Fractol");
	f.m_i = mlx_new_image(f.m_p, IMG_W, IMG_H);
	f.m_d = (int *)mlx_get_data_addr(f.m_i, &f.b, &f.s, &f.e);
	if (id == 0)
		julia(&f);
	if (id == 1)
		mandelbrot(&f);
	if (id == 2)
		burningship(&f);
	mlx_put_image_to_window(f.m_p, f.m_w, f.m_i, 0, 0);
	mlx_hook(f.m_w, 2, 1, &keys_hook, &f);
	mlx_hook(f.m_w, 4, 0, &mouse_hook, &f);
	mlx_hook(f.m_w, 6, 0, &mouse_move, &f);
	mlx_loop(f.m_p);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		if (!ft_strcmp(av[1], "Julia"))
			return (fractol(0));
		if (!ft_strcmp(av[1], "Mandelbrot"))
			return (fractol(1));
		if (!ft_strcmp(av[1], "Burningship"))
			return (fractol(2));
	}
	usage();
	return (0);
}
