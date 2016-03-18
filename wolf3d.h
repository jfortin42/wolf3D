/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:06:23 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/18 18:00:07 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_X 1900
# define WIN_Y 1080

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)

# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define PLUS 65451
# define MINUS 65453
# define STAR 65450
# define SLASH 65455
# define PAGE_UP 65365
# define PAGE_DOWN 65366
# define ZERO 65438
# define ESC 53

# define WELCOME "Welcome to wolf3D by jfortin"
# define PRESS "Press any key to start"

# define CONTROLS "            CONTROLS"
# define H_UP "     move up    |    up"
# define H_DOWN "    move down   |   down"
# define H_LEFT "    move left   |   left"
# define H_RIGHT "   move right   |   right"
# define H_PLUS "    zoom in     |     +"
# define H_MINUS "    zoom out    |     -"
# define H_STAR "increase height |     *"
# define H_SLASH "decrease height |     /"
# define H_PAGE_UP "   next colors  | page up"
# define H_PAGE_DOWN "previous colors | page down"
# define H_ZERO "     reset      |     0"
# define H_ESC "  exit program  |    esc"

# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include "libft/includes/libft.h"

typedef struct		s_env
{
	int				fd;
	void			*mlx;
	void			*win;
	char			**line;
	size_t			cnt_line;
	size_t			cnt_col;
	int				**tab;
	int				x;
	int				y;
	int				x_prim;
	int				y_prim;
	int				color;

	int				max_height;

	int				zoom;
	int				lr;
	int				ud;
	int				height;
	int				contrast;

	int				tmpx;
	int				tmpy;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				tmp_error;
	int				error;

	void			*im;
	char			*imc;
	int				imlen;
	int				bpp;
	int				endi;
}					t_env;

void				ft_parse(t_env *e, char *line);
void				ft_draw(int x2, int y2, t_env *e);
void				ft_put_help(t_env e);
void				ft_put_pixel(t_env *e, int x, int y, int color);

#endif
