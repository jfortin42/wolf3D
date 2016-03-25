/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 10:23:53 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/25 13:44:25 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_ray(t_env *e, int x)
{
	e->camera = 2 * x / (double)(WIN_X) - 1;
	e->rpos.x = e->pos.x;
	e->rpos.y = e->pos.y;
	e->rdir.x = e->dir.x + e->rplane.x * e->camera;
	e->rdir.y = e->dir.y + e->rplane.y * e->camera;
	e->rmap.x = (int)e->rpos.x;
	e->rmap.y = (int)e->rpos.y;
	e->rdisd.x = sqrt(1 + (e->rdir.y * e->rdir.y) / (e->rdir.x * e->rdir.x));
	e->rdisd.y = sqrt(1 + (e->rdir.x * e->rdir.x) / (e->rdir.y * e->rdir.y));
	e->hit = 0;
}

void	ft_direction_ray(t_env *e)
{
	if (e->rdir.x < 0)
	{
		e->step.x = -1;
		e->rdist.x = (e->rpos.x - e->rmap.x) * e->rdisd.x;
	}
	else
	{
		e->step.x = 1;
		e->rdist.x = (e->rmap.x + 1.0 - e->rpos.x) * e->rdisd.x;
	}
	if (e->rdir.y < 0)
	{
		e->step.y = -1;
		e->rdist.y = (e->rpos.y - e->rmap.y) * e->rdisd.y;
	}
	else
	{
		e->step.y = 1;
		e->rdist.y = (e->rmap.y + 1.0 - e->rpos.y) * e->rdisd.y;
	}
}

void	ft_hit_ray(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->rdist.x < e->rdist.y)
		{
			e->rdist.x += e->rdisd.x;
			e->rmap.x += e->step.x;
			e->wall = 0;
		}
		else
		{
			e->rdist.y += e->rdisd.y;
			e->rmap.y += e->step.y;
			e->wall = 1;
		}
		if (e->map[e->rmap.x][e->rmap.y] == 1)
			e->hit = 1;
	}
}

void	ft_size_ray(t_env *e)
{
	double dist;

	if (e->wall == 0)
		dist = fabs((e->rmap.x - e->rpos.x
					+ (1 - e->step.x) / 2) / e->rdir.x);
	else
		dist = fabs((e->rmap.y - e->rpos.y
					+ (1 - e->step.y) / 2) / e->rdir.y);
	e->rh = abs((int)(WIN_Y / dist));
	e->wstart = (-1 * (e->rh)) / 2 + WIN_Y / 2;
	if (e->wstart < 0)
		e->wstart = 0;
	e->wend = e->rh / 2 + WIN_Y / 2;
	if (e->wend >= WIN_Y)
		e->wend = WIN_Y - 1;
}
