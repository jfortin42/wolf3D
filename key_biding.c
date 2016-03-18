/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_biding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 17:43:54 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/17 18:23:49 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_hit(int keycode, t_env *e)
{
	if (keycode == PLUS || keycode == MINUS)
		e->itm = (keycode == PLUS ? 1 : -1);
	if (keycode == ZERO || keycode == NUM_ZERO)
		e->reset = 1;
	if (keycode == SPACE)
		e->bj = 1;
	if (keycode == ONE || keycode == TWO)
		e->av = (keycode == ONE ? "mandelbrot" : "julia");
	if (keycode == THREE || keycode == FOUR)
		e->av = (keycode == THREE ? "burning" : "mandelbis");
	if (keycode == ONE || keycode == TWO || keycode == THREE || keycode == FOUR)
	{
		ft_ini_fract(e);
		ft_settings(e);
	}
	if (!e->check)
		ft_settings(e);
	e->check = 1;
	return (0);
}

int		ft_key_release(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(1);
	if (keycode == PLUS || keycode == MINUS)
		e->itm = 0;
	if (keycode == ZERO || keycode == NUM_ZERO)
		e->reset = 0;
	if (keycode == SPACE)
		e->bj = 0;
	return (0);
}

void	ft_do_key_action(t_env *e)
{
	if (e->itm == -1 && e->iter_max > 10)
		e->iter_max -= 10;
	if (e->itm == 1)
		e->iter_max += 10;
	if (e->reset == 1)
		ft_ini_fract(e);
}

int		ft_core(t_env *e)
{
	if (e->check == 0)
		return (0);
	mlx_destroy_image(e->mlx, e->im);
	e->im = mlx_new_image(e->mlx, IM_X, WIN_Y);
	ft_do_key_action(e);
	ft_print_fract(e);
	mlx_put_image_to_window(e->mlx, e->win, e->im, 0, 0);
	return (0);
}
