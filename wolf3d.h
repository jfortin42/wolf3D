/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:06:23 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/27 18:20:00 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIN_X 1280
# define WIN_Y 720

# define MAP1 "maps/map01.w3d"
# define MAP2 "maps/map02.w3d"
# define MAP3 "maps/map03.w3d"
# define SKY "textures/sky.xpm"

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)

# define W 13
# define S 1
# define A 0
# define D 2
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
# define NUM_ZERO 29
# define ZERO 82
# define ONE 18
# define TWO 19
# define THREE 20
# define ESC 53

# define COLOR_SKY 0xA9EAFF
# define COLOR_FLOOR 0x3A9D23
# define COLOR_NORTH 0x116CC7
# define COLOR_SOUTH 0xDD985C
# define COLOR_EAST 0xA91101
# define COLOR_WEST 0xEFD242

# define WELCOME    "Welcome to wolf3D by jfortin"
# define CHOOSE     "  Choose a level to start   "
# define LEVEL_KEY  "    LEVEL    |    KEY       "
# define LEVEL1     "      1      |     1        "
# define LEVEL2     "      2      |     2        "
# define LEVEL3     "      3      |     3        "

# define CONTROLS    "            CONTROLS           "
# define H_MOVE      "   shiftings : up down / W S   "
# define H_ROTATE    "     rotate  : left right / A D"
# define H_SPEED     "change speed :       +  -      "
# define H_ZERO      "     reset   :       0         "
# define H_ESC       "exit program :      esc        "

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

typedef struct		s_img
{
	void			*im;
	char			*imc;
	int				imlen;
	int				bpp;
	int				endi;
}					t_img;

typedef struct		s_env
{
	char			*choice;
	int				fd;
	char			**line;
	int				cnt_line;
	int				cnt_col;
	int				**map;
	int				check;

	void			*mlx;
	void			*win;
	int				color;

	t_img			img;
	t_img			sky;

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
	int				up;
	int				down;
	int				left;
	int				right;
}					t_env;

void				ft_welcome(t_env e);
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
void				ft_init(t_env *e);
void				ft_settings(t_env e);

#endif
