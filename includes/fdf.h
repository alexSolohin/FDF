/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:22:50 by lliza             #+#    #+#             */
/*   Updated: 2020/02/05 18:46:36 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define FT_SWAP(a, b) { b = ((a) + (b)); a = ((b) - (a)); b = ((b) - (a)); }
# define FT_ABS(x) (((x) < 0) ? (-(x)) : (x))
# define FT_MIN(a, b) (((a) < (b)) ? (a) : (b))
# define RED 0xFF0000
# define GREEN 0xFF00
# define BLUE 0xFF
# define ENDIAN 0
# define WIDTH 2000
# define HEIGHT 1200
# define MENU_W WIDTH / 7
# define MENU_BG 0xDD00CCCC
# define B_W MENU_W
# define B_H 40
# define BUTTONS_NUM 11
# define MENU_H B_H * BUTTONS_NUM + 10
# define B_TEXT_COLOR 0xDD999999

typedef enum		e_bool
{
	false,
	true
}					t_bool;
typedef enum		e_proj
{
	parallel,
	ISO
}					t_proj;
typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	unsigned		rgb;
}					t_point;
typedef struct		s_mouse
{
	int				left_key;
	int				right_key;
	int				third_key;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}					t_mouse;
typedef struct		s_keyboard
{
	t_bool			is_pressed;
}					t_keyboard;
typedef	struct		s_button
{
	int				y_offset;
	char			*text;
	struct s_button	*next;
}					t_button;
typedef struct		s_menu
{
	t_button		*buttons;
	int				folded;
}					t_menu;

typedef struct		s_vision
{
	int				zoom;
	t_proj			*proj;
	double			angle_x;
	double			angle_y;
	double			angle_z;
	float			z_divisior;
	int				x_offset;
	int				y_offset;
}					t_vision;

typedef struct		s_fdf
{
	int				win_w;
	int				win_h;
	int				**map;
	t_point			**mx;
	void			*mlx;
	void			*win;
	void			*img;
	char			*pixels_arr;
	int				bits_per_pixel;
	int				line_size;
	int				zoom;
	t_mouse			*mouse;
	t_keyboard		*keyboard;
	int				map_width;
	int				map_height;
	double			x_axis;
	double			y_axis;
	double			z_axis;
	int				x_offset;
	int				y_offset;
	int				z_min;
	int				z_max;
	int				color_zero;
	int				color_max;
	t_proj			projection;
	t_menu			*menu;
	t_vision		*vision;
	int				error;
	int				error2;
	int				color_inversion;
	int				disco;
	int				disco_off;
}					t_fdf;
/*
**			<========================== init =========================>
*/
int					ft_fdf_init_img(t_fdf *fdf);
void				ft_init_menu(t_fdf *fdf);
void				ft_init_menu_button_bg(t_fdf *fdf);
t_button			*ft_init_buttons(void);
void				ft_fdf_init(t_fdf *fdf, int ac, char **av, t_mouse *mouse);
int					**ft_maparr(char *file_name, t_fdf *fdf);
/*
**			<====================== end of init ======================>
*/
/*
**			<========================= color =========================>
*/
void				ft_init_point_color(t_point *p, t_fdf *fdf);
int					calculate_p_color\
	(t_fdf *fdf, t_point *start, t_point *end, t_point *curr);
/*
**			<===================== end ofcolor =======================>
*/
/*
**			<========================= draw ==========================>
*/
void				isometric(int *x, int *y, double z);
void				ft_modify_point(t_point *p, t_fdf *fdf);
void				ft_modify_mx(t_fdf *fdf, void (*f)(void *, void *));
void				ft_draw_map(t_fdf *fdf);
t_point				projection(t_point p, t_fdf *fdf);
void				rotate(t_fdf *fdf, int keycode);
void				rotate_x_axis(int *y, int *z, double angle_x);
void				rotate_y_axis(int *x, int *z, double angle_y);
void				rotate_z_axis(int *x, int *y, int z);
int					ft_mouse_zoom(int keycode, int x, int y, void *param);
t_vision			*ft_vision(t_fdf *fdf);
/*
**			<====================== end of draw ======================>
*/
int					ft_mouse_key_press(int keycode, int x, int y, void *param);
int					ft_mouse_key_release\
	(int keycode, int x, int y, void *param);
int					ft_mouse_hook(int button, int x, int y, void *param);
int					ft_mouse_move_rotate(int x, int y, void *param);
int					ft_keyboard_hook(int key, void *param);
/*
**			<========================= utils =========================>
*/
int					ft_close(void *param);
void				ft_clear(t_fdf *fdf);
int					ft_fdf_usage(void);
void				ft_print_point(t_point p);
void				ft_find_z_range(t_fdf *fdf);
int					ft_in_menu_button(int x, int y);
/*
**			<===================== end of utils ======================>
*/
void				ft_zoom(int keycode, t_fdf *fdf);
void				ft_divisior(int keycode, t_fdf *fdf);
#endif
