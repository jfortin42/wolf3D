/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:06:23 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/25 15:19:18 by jfortin          ###   ########.fr       */
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

# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define PLUS 69
# define MINUS 78
# define STAR 67
# define SLASH 75
# define PAGE_UP 116
# define PAGE_DOWN 121
# define ZERO 82
# define ESC 53

#define COLOR_SKY 0xA9EAFF
#define COLOR_FLOOR 0x3A9D23
#define COLOR_NORTH 0x048B9A
#define COLOR_SOUTH 0xDD985C
#define COLOR_EAST 0xA91101
#define COLOR_WEST 0xEFD242


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

	double			camera;
	int				wall;
	int				hit;
	t_dxy			pos;
	t_dxy			dir;
	t_dxy			rplane;
	t_dxy			rpos;
	t_dxy			rdir;
	t_dxy			rdist;
	t_dxy			rdisd;
	t_xy			rmap;
	t_xy			step;

	int				wstart;
	int				wend;
	int				rh;

	double			speed;
	int				left;
	int				right;
	int				up;
	int				down;

}					t_env;

void				ft_parse(t_env *e, char *line);
void				ft_put_help(t_env e);
void				ft_put_pixel(t_env *e, int x, int y, int color);
int					ft_key_hit(int keycode, t_env *e);
int					ft_key_release(int keycode, t_env *e);
int					ft_core(t_env *e);
void				ft_disp_screen(t_env *e);
void				ft_size_ray(t_env *e);
void				ft_hit_ray(t_env *e);
void				ft_direction_ray(t_env *e);
void				ft_init_ray(t_env *e, int x);
void				ft_move(t_env *e);

#endif
