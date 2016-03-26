/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:30:14 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/26 14:06:43 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_welcome(t_env e)
{
	int	m_x;
	int	m_y;

	m_x = 750;
	m_y = 450;
	mlx_string_put(e.mlx, e.win, m_x, m_y, 0xFF9933, WELCOME);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 20, 0xFF9933, CHOOSE);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 50, 0xFF9933, LEVEL_KEY);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 70, 0xFF9933, LEVEL1);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 90, 0xFF9933, LEVEL2);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 110, 0xFF9933, LEVEL3);
}

void	ft_settings(t_env e)
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
