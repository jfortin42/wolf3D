/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:06:23 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/24 17:45:57 by jfortin          ###   ########.fr       */
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

#define COLOR_SKY 0xA9EAFF
#define COLOR_FLOOR 0x3A9D23
#define COLOR_NORTH 0x123456
#define COLOR_SOUTH 0x234567
#define COLOR_EST 0x345678
#define COLOR_WEST 0x456789


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
# include <math.h>
# include "libft/includes/libft.h"

typedef struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

typedef struct		s_dxy
{
	double			x;
	double			y;
}					t_dxy;

typedef struct		s_env
{
	int				fd;
	char			**line;
	int				cnt_line;
	int				cnt_col;
	int				**map;
	int				check;

	void			*mlx;
	void			*win;
	int				color;

	void			*im;
	char			*imc;
	int				imlen;
	int				bpp;
	int				endi;

	t_dxy			pos;
	t_dxy			dir;
	t_dxy			plane;
	int				wstart;
	int				wend;

	double			speed;
	int				lr;
	int				ud;

}					t_env;

void				ft_parse(t_env *e, char *line);
void				ft_put_help(t_env e);
void				ft_put_pixel(t_env *e, int x, int y, int color);
int					ft_key_hit(int keycode, t_env *e);
int					ft_key_release(int keycode, t_env *e);
int					ft_core(t_env *e);
void				ft_disp_screen(t_env *e);

#endif
