/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:30:14 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/25 17:47:21 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_settings (t_env e)
{
	int	m_x;
	int	m_y;

	m_x = 1580;
	m_y = 0;
	mlx_string_put(e.mlx, e.win, m_x, m_y, 0xffffff, CONTROLS);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 16, 0xffffff, H_MOVE);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 32, 0xffffff, H_ROTATE);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 48, 0xffffff, H_SPEED);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 64, 0xffffff, H_ZERO);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 80, 0xffffff, H_ESC);
}
