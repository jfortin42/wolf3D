/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_biding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 17:43:54 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/24 17:45:59 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_key_hit(int keycode, t_env *e)
{
	e->fd = 0;
	if (keycode == ESC)
		exit(1);
	e->check = 1;
	return (0);
}

int		ft_key_release(int keycode, t_env *e)
{
	e->fd = 0;
	if (keycode == ESC)
		exit(1);
	return (0);
}

void	ft_do_key_action(t_env *e)
{
	e->fd = 0;
}

int		ft_core(t_env *e)
{
	if (e->check == 0)
		return (0);
	mlx_destroy_image(e->mlx, e->im);
	e->im = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	ft_do_key_action(e);
	ft_disp_screen(e);
	mlx_put_image_to_window(e->mlx, e->win, e->im, 0, 0);
	//ft_settings(e);
	return (0);
}
