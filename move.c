/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemonet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:36:31 by cemonet           #+#    #+#             */
/*   Updated: 2016/03/25 16:17:58 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_rotate(t_env *e, int advance)
{
	double	dir;
	double	plane;

	dir = e->dir.x;
	plane = e->rplane.x;
	e->dir.x = e->dir.x * cos(advance * 0.1)
		- e->dir.y * sin(advance * 0.1);
	e->dir.y = dir * sin(advance * 0.1)
		+ e->dir.y * cos(advance * 0.1);
	e->rplane.x = e->rplane.x * cos(advance * 0.1)
		- e->rplane.y * sin(advance * 0.1);
	e->rplane.y = plane * sin(advance * 0.1)
		+ e->rplane.y * cos(advance * 0.1);
}

void	ft_move(t_env *e)
{
	if (e->up)
	{
		if (!(e->map[(int)(e->pos.x + e->dir.x * e->speed)][(int)(e->pos.y)]))
			e->pos.x += e->dir.x * e->speed;
		if (!(e->map[(int)(e->pos.x)][(int)(e->pos.y + e->dir.y * e->speed)]))
			e->pos.y += e->dir.y * e->speed;
	}
	if (e->left)
		ft_rotate(e, 1);
	if (e->right)
		ft_rotate(e, -1);
	if (e->down)
	{
		if (!(e->map[(int)(e->pos.x - e->dir.x * e->speed)][(int)(e->pos.y)]))
			e->pos.x -= e->dir.x * e->speed;
		if (!(e->map[(int)(e->pos.x)][(int)(e->pos.y - e->dir.y * e->speed)]))
			e->pos.y -= e->dir.y * e->speed;
	}
}
