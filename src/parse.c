/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:03:19 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/28 16:50:36 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

static void	ft_freestr2d(t_env *e)
{
	int		i;

	i = 0;
	while (e->line[i])
	{
		ft_strdel(&(e->line[i]));
		++i;
	}
	ft_strdel(&(e->line[i]));
	free(e->line);
}

static int	ft_split_line(t_env *e)
{
	char	*line;
	int		ret;

	ret = 0;
	if (get_next_line(e->fd, &line) == 1)
	{
		e->line = ft_strsplit(line, ' ');
		free(line);
		++ret;
	}
	else
		free(line);
	return (ret);
}

static void	ft_int2d(t_env *e, char *file)
{
	char	*line;
	int		len;

	e->cnt_col = 0;
	e->cnt_line = 0;
	while (get_next_line(e->fd, &line) == 1)
	{
		++e->cnt_line;
		len = ft_strlen(line);
		free(line);
	}
	free(line);
	if (e->cnt_line == 0 || len == 0)
		ft_error("read has failed");
	e->map = (int **)ft_memalloc(sizeof(int *) * e->cnt_line);
	close(e->fd);
	e->fd = open(file, O_RDONLY);
	ft_split_line(e);
	while (e->line[e->cnt_col])
		++e->cnt_col;
	while (e->cnt_line > 0)
	{
		e->map[e->cnt_line - 1] = (int*)ft_memalloc(sizeof(int) * e->cnt_col);
		--e->cnt_line;
	}
}

void		ft_parse(t_env *e, char *file)
{
	int	nbr_col;

	nbr_col = 0;
	if ((e->fd = open(file, O_RDONLY)) <= 0)
		ft_error("open has failed");
	ft_int2d(e, file);
	while (nbr_col < e->cnt_col)
	{
		e->map[0][nbr_col] = ft_atoi(e->line[nbr_col]);
		++nbr_col;
	}
	ft_freestr2d(e);
	while (ft_split_line(e) == 1)
	{
		++e->cnt_line;
		nbr_col = -1;
		while (e->line[++nbr_col])
			e->map[e->cnt_line][nbr_col] = ft_atoi(e->line[nbr_col]);
		ft_freestr2d(e);
		if (nbr_col != e->cnt_col)
			ft_error("invalid map");
	}
	++e->cnt_line;
	e->check = 1;
}
