/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_biding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 17:43:54 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/27 17:13:32 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_key_hit(int keycode, t_env *e)
{
	if (!e->check && (keycode == ONE || keycode == TWO))
		keycode == ONE ? ft_parse(e, MAP1) : ft_parse(e, MAP2);
	if (!e->check && keycode == THREE)
		ft_parse(e, MAP3);
	if (keycode == UP || keycode == W)
		e->up = 1;
	if (keycode == DOWN || keycode == S)
		e->down = 1;
	if (keycode == LEFT || keycode == A)
		e->left = 1;
	if (keycode == RIGHT || keycode == D)
		e->right = 1;
	if ((keycode == MINUS && e->speed > 0.02)
			|| (keycode == PLUS && e->speed < 0.3))
		e->speed += (keycode == PLUS ? 0.01 : -0.01);
	if (keycode == ZERO || keycode == NUM_ZERO)
		ft_init(e);
	if (keycode == ESC)
		exit(1);
	return (0);
}

int		ft_key_release(int keycode, t_env *e)
{
	if (keycode == UP || keycode == W)
		e->up = 0;
	if (keycode == DOWN || keycode == S)
		e->down = 0;
	if (keycode == LEFT || keycode == A)
		e->left = 0;
	if (keycode == RIGHT || keycode == D)
		e->right = 0;
	return (0);
}

int		ft_core(t_env *e)
{
	if (e->check == 0)
		return (0);
	mlx_destroy_image(e->mlx, e->img.im);
	e->img.im = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	ft_move(e);
	ft_disp_screen(e);
	mlx_put_image_to_window(e->mlx, e->win, e->sky.im, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->img.im, 0, 0);
	ft_settings(*e);
	return (0);
}
