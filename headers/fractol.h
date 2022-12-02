/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:35:56 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/02 14:37:26 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "ft_printf.h"

# define SIZE_X 800
# define SIZE_Y 800
# define TITLE "FRACT-OL"

# define WRG_NB_ARG "NO OPTION SELECTED\n\nSelect one Fractal option:\nJulia : -j\n\
Julia cubed : -J3\nMandelbrot : -m\nBurning Ship : -b\n\nFor Julia (-j) \
and Julia cubed (-J3), you need to give the Real (Re)\nand Imaginary (Im) \
Value of c.\nExample : -j -1.21 0.23\n\nSelect one color option:\
\nRainbow : -r\nSunset : -s\nVirus Matrix : -m\nCustom : -c\n"

# define WRG_FRAC "Bad option selection\nSelect one Fractal option:\nJulia : -j\n\
Julia cubed : -J3\nMandelbrot : -m\nBurning Ship : -b\n\nFor Julia (-j)\
and Julia cubed (-J3), you need to give the Real (Re) and Imaginary (Im) Value of c.\n\
Example : -j -1.21 0.23\n"

# define WRG_COLOR "Bad option selection\n\nSelect one color palet option:\nRainbow : \
-r\nSunset : -s\nVirus Matrix : -m\nCustom : -c\n"

# define NO_VALUE "No value for c given\n\nFor Julia (-j) and Julia cubed (-J3) \
please give two float arguments\nThey must be beetwen -2.0 and 2.0 ex: -j -1.25 0.375\n\
(the 1st is the real part (Re) of c)\nNo more than 4 digits are accepted\n"

# define BAD_VALUE "Bad value selection for c\n\nFor Julia and cubed Julia please give two \
float arguments.\nThey must be between -2.0 and 2.0 ex: -j -1.25 0.375\n\
(the 1st is the real part (Re) of c)\n no more than 4 digits are accepted.\n"

# define WELCOME "Welcome to Fract-OL 1.0\n\nNow you can enjoy the program!\n\
\nClick on the mouse to activate the image\
\nPress the SPACE touch to free the mouse and allow \ndynamic motion for \
Julia and Julia Cubed\n\nYou can use NumPad to modifiy c value\n\
Touch '4' & '6' for Re(c)\nTouch '8' & '2' for Im(c)\n\n\
More Features are coming (TIA and curvatures coloring) Be patient! =)\
\n\nAll right reserved ©jlitaudo Corporation\n"

# define BASE_DEC "0123456789"

# define MID_SIZE_X 400
# define MID_SIZE_Y 400
# define SCROLL_UP 4
# define SCROLL_DW 5
# define MAX_IT 60

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_cmplx
{
	double	re;
	double	im;
	double	re_temp;
	double	im_temp;
	double	mod;
	double	sum1;
	double	sum2;
}t_cmplx;

typedef struct s_rgba
{
	unsigned char	blu;
	unsigned char	gre;
	unsigned char	red;
	unsigned char	tra;
}t_rgba;

typedef union u_color
{
	unsigned int	col;
	t_rgba			rgba;
}t_color;

typedef struct s_info
{
	char	*mode;
	char	*c_re;
	char	*c_im;
	char	*color_meth;
	char	*color_palet;
}t_info;

typedef struct s_win
{
	void			*mlx;
	void			*win;
	double			zoom;
	double			mv_up;
	double			mv_right;
	int				nb_it_max;
	int				pause_init;
	int				nb_categ;
	char			fractal;
	char			color;
	char			**argv_col;
	t_data			img1;
	t_data			img2;
	t_data			*img_print;
	t_cmplx			c;
	t_color			*pal;
	t_info			info;
	unsigned int	(*fract)(double, double, struct s_win *);
	t_color			*(*make)(char **str);
}t_win;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			init_window(int argc, char **argv, t_win *win);
void			check_option(int argc, char **argv, t_win *win);
void			init_option(t_win *win);
void			init_option2(t_win *win);
void			check_custom_color(char **color);
void			draw_frac(t_win *win);
char			**ft_strupcase(char **str);
char			*ft_itoa(double nb);
float			ft_atof(char *str);
int				gate_away(t_win	*win);
int				contain(char *str, char c);
int				mouse_param(int button, int x, int y, t_win *win);
int				keyboard_action(int key, t_win *win);
int				ft_strcmp(const char *s1, const char *s2);
unsigned int	make_julia(double x, double y, t_win *win);
unsigned int	make_burning_ship(double x, double y, t_win *win);
unsigned int	make_mandelbrot(double x, double y, t_win *win);
unsigned int	make_julia3(double x, double y, t_win *win);
unsigned int	smooth_color(int it, float mod, t_win *win);
unsigned int	ft_atoi_base(char *str);
int				mouse_modif_param(int x, int y, t_win *win);
t_color			*make_rainbow(char **str);
t_color			*make_sunset(char **str);
t_color			*make_matrix_virus(char **str);
t_color			*make_custom(char **str);
#endif