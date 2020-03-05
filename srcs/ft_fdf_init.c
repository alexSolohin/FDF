/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:17:00 by lliza             #+#    #+#             */
/*   Updated: 2020/02/05 18:43:06 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "fdf.h"
#include "ft_fdf_key_num.h"

static int	ft_init_hook(t_fdf *fdf)
{
	mlx_hook(fdf->win, MOUSE_MOVE, 0, ft_mouse_move_rotate, fdf);
	mlx_hook(fdf->win, MOUSE_BUTTON_PRESS, 0, ft_mouse_key_press, fdf);
	mlx_hook(fdf->win, MOUSE_BUTTON_RELEASE, 0, ft_mouse_key_release, fdf);
	mlx_hook(fdf->win, KEY_BUTTON_PRESS, 0, ft_keyboard_hook, fdf);
	mlx_hook(fdf->win, ESC_BUTTON_PRESS, 0, ft_close, fdf);
	return (0);
}

static void	ft_fdf_init_colors(t_fdf *fdf, int ac, char **av)
{
	if (ac > 3)
	{
		if (!ft_strcmp(av[2], "--set_colors"))
		{
			fdf->color_max = ft_atoi_base(av[3], 16);
			fdf->color_zero = ft_atoi_base(av[4], 16);
			return ;
		}
	}
	fdf->color_zero = 0x00FF00;
	fdf->color_max = 0xFFFFFF;
}

void		ft_fdf_init(t_fdf *fdf, int ac, char **av, t_mouse *mouse)
{
	fdf->mouse = mouse;
	if (!(fdf->menu = (t_menu *)malloc(sizeof(t_menu))))
		exit(-1);
	fdf->menu->buttons = ft_init_buttons();
	fdf->menu->folded = 1;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT,
		"rmaxima -*- FDF -*- lliza");
	ft_fdf_init_img(fdf);
	fdf->map = ft_maparr(av[1], fdf);
	ft_find_z_range(fdf);
	ft_fdf_init_colors(fdf, ac, av);
	fdf->x_offset = 0;
	fdf->y_offset = 0;
	fdf->x_axis = 0;
	fdf->y_axis = 0;
	fdf->vision = ft_vision(fdf);
	fdf->color_inversion = 0;
	fdf->error = 0;
	fdf->error2 = 0;
	fdf->disco_off = 1;
	ft_init_hook(fdf);
}
