/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_biding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 17:43:54 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/25 15:23:10 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_key_hit(int keycode, t_env *e)
{
	if (keycode == UP)
		e->up = 1;
	if (keycode == DOWN)
		e->down = 1;
	if (keycode == LEFT)
		e->left = 1;
	if (keycode == RIGHT)
		e->right = 1;
	if (keycode == ESC)
		exit(1);
	e->check = 1;
	return (0);
}

int		ft_key_release(int keycode, t_env *e)
{
	if (keycode == UP)
		e->up = 0;
	if (keycode == DOWN)
		e->down = 0;
	if (keycode == LEFT)
		e->left = 0;
	if (keycode == RIGHT)
		e->right = 0;
	if (keycode == ESC)
		exit(1);
	return (0);
}

int		ft_core(t_env *e)
{
	if (e->check == 0)
		return (0);
	mlx_destroy_image(e->mlx, e->im);
	e->im = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	ft_move(e);
	ft_disp_screen(e);
	mlx_put_image_to_window(e->mlx, e->win, e->im, 0, 0);
	//ft_settings(e);
	return (0);
}
