/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:31:04 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/24 18:03:04 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_put_pixel(t_env *e, int x, int y, int color)
{
	int	*tmp;

	if (y >= WIN_Y || x >= WIN_X || x < 0 || y < 0)
		return ;
	tmp = (int *)&e->imc[(y * e->imlen) + (x * (e->bpp / 8))];
	*tmp = color;
}

void	ft_disp_vert(t_env *e, int x)
{
	int	y;

	y = 0;
	while (y < e->wstart)
	ft_put_pixel(e, x, y++, COLOR_SKY);
	while (y >= e->wstart && y <= e->wend)
	ft_put_pixel(e, x, y++, 0x555555);
	while (y < WIN_Y)
	ft_put_pixel(e, x, y++, COLOR_FLOOR);
}

void	ft_disp_screen(t_env *e)
{
	int	x;

	x = 0;
	while (x < WIN_X)
		ft_disp_vert(e, x++);
}
