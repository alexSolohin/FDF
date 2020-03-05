/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:50:58 by lliza             #+#    #+#             */
/*   Updated: 2020/02/05 18:58:54 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "ft_fdf_key_num.h"
#include "libft.h"

static void		ft_move(int key, t_fdf *fdf)
{
	if (key == ARROW_LEFT)
		fdf->vision->x_offset -= 10;
	else if (key == ARROW_RIGHT)
		fdf->vision->x_offset += 10;
	else if (key == ARROW_UP)
		fdf->vision->y_offset -= 10;
	else if (key == ARROW_DOWN)
		fdf->vision->y_offset += 10;
}

static void		keyboard_rotate(int key, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	if (key == NUM_PAD_2 || key == MAIN_PAD_2)
		fdf->vision->angle_x += 0.05;
	else if (key == NUM_PAD_8 || key == MAIN_PAD_8)
		fdf->vision->angle_x -= 0.05;
	else if (key == NUM_PAD_4 || key == MAIN_PAD_4)
		fdf->vision->angle_y -= 0.05;
	else if (key == NUM_PAD_6 || key == MAIN_PAD_6)
		fdf->vision->angle_y += 0.05;
}

static void		ft_apply_projection(t_fdf *fdf, int key)
{
	fdf->vision->angle_x = 0;
	fdf->vision->angle_y = 0;
	fdf->vision->angle_z = 0;
	if (key == MAIN_PAD_P)
		fdf->projection = parallel;
	else if (key == MAIN_PAD_I)
		fdf->projection = ISO;
}

static void		ft_keyboard_hook_follow(int key, void *param)
{
	t_fdf *fdf;

	fdf = param;
	if (key == MAIN_PAD_C)
		fdf->color_inversion ^= 1;
	else if (key == MAIN_PAD_CUP || key == MAIN_PAD_CDOWN)
	{
		fdf->disco_off = 0;
		if (key == MAIN_PAD_CUP)
			fdf->disco += 10;
		else
			fdf->disco -= 10;
	}
	else if (key == MAIN_PAD_D)
		fdf->disco_off = 1;
}

int				ft_keyboard_hook(int key, void *param)
{
	if (key == ARROW_UP || key == ARROW_DOWN ||
		key == ARROW_LEFT || key == ARROW_RIGHT)
		ft_move(key, param);
	else if (key == MAIN_PAD_PLUS || key == MAIN_PAD_MINUS ||
			key == NUM_PAD_PLUS || key == NUM_PAD_MINUS)
		ft_zoom(key, param);
	else if (key == NUM_PAD_2 || key == MAIN_PAD_2
		|| key == NUM_PAD_4 || key == MAIN_PAD_4
		|| key == NUM_PAD_6 || key == MAIN_PAD_6
		|| key == NUM_PAD_8 || key == MAIN_PAD_8)
		keyboard_rotate(key, param);
	else if (key == MAIN_PAD_ESC)
		ft_close(param);
	else if (key == MAIN_PAD_I || key == MAIN_PAD_P)
		ft_apply_projection(param, key);
	else if (key == MAIN_PAD_MORE || key == MAIN_PAD_LESS)
		ft_divisior(key, param);
	else if (key == MAIN_PAD_C || key == MAIN_PAD_CUP ||
			key == MAIN_PAD_CDOWN || key == MAIN_PAD_D)
		ft_keyboard_hook_follow(key, param);
	else
		return (0);
	ft_draw_map(param);
	return (0);
}
