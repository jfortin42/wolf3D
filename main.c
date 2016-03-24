/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 18:20:56 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/24 17:43:19 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "wolf3d");
	e->im = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->imc = mlx_get_data_addr(e->im, &e->bpp, &e->imlen, &e->endi);
	e->pos.x = 2;
	e->pos.y = 2;
	e->dir.x = 1;
	e->dir.y = 0;
	e->wstart = 100;
	e->wend = 300;
}

int		main(int ac, char **av)
{
	t_env e;

	e.check = 0;
	ac != 2 ? ft_error("Number of argument incorrect") : ft_parse(&e, av[1]);
	ft_init(&e);
	mlx_string_put(e.mlx, e.win, 400, 250, 0xFF9933, WELCOME);
	mlx_string_put(e.mlx, e.win, 450, 279, 0xFF9933, PRESS);
	mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, ft_key_hit, &e);
	mlx_hook(e.win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &e);
	mlx_loop_hook(e.mlx, ft_core, &e);
	mlx_loop(e.mlx);
	return (0);
}
