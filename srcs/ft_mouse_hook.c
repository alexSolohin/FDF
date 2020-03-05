/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:29:53 by lliza             #+#    #+#             */
/*   Updated: 2020/02/05 15:40:20 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "ft_fdf_key_num.h"
#include "libft.h"

int		ft_mouse_zoom(int keycode, int x, int y, void *param)
{
	t_fdf	*fdf;
	int		zoom_original;

	(void)x;
	(void)y;
	fdf = param;
	zoom_original = fdf->vision->zoom;
	if (keycode == MOUSE_SCROLL_DOWN)
		fdf->vision->zoom -= fdf->vision->zoom > 1 ? 1 : 0;
	else if (keycode == MOUSE_SCROLL_UP)
		fdf->vision->zoom += 1;
	if (zoom_original != fdf->vision->zoom)
		ft_draw_map(fdf);
	return (0);
}

int		ft_mouse_key_press(int keycode, int x, int y, void *param)
{
	t_fdf *fdf;

	fdf = param;
	if (keycode == MOUSE_LEFT_BUTTON)
		fdf->mouse->left_key = 1;
	else if (keycode == MOUSE_RIGHT_BUTTON)
		fdf->mouse->right_key = 1;
	else if (keycode == MOUSE_THIRD_BUTTON)
		fdf->mouse->third_key = 1;
	else if (keycode == MOUSE_SCROLL_DOWN || keycode == MOUSE_SCROLL_UP)
		return (ft_mouse_zoom(keycode, x, y, param));
	fdf->mouse->x1 = x;
	fdf->mouse->y1 = y;
	if (fdf->mouse->left_key && ft_in_menu_button(x, y))
	{
		fdf->menu->folded ^= 1;
		ft_draw_map(fdf);
	}
	return (0);
}

int		ft_mouse_key_release(int keycode, int x, int y, void *param)
{
	t_fdf *fdf;

	fdf = param;
	(void)keycode;
	(void)x;
	(void)y;
	fdf->mouse->left_key = 0;
	fdf->mouse->right_key = 0;
	fdf->mouse->third_key = 0;
	return (0);
}

int		ft_mouse_move_rotate(int x, int y, void *param)
{
	((t_fdf *)param)->mouse->x0 = ((t_fdf *)param)->mouse->x1;
	((t_fdf *)param)->mouse->y0 = ((t_fdf *)param)->mouse->y1;
	((t_fdf *)param)->mouse->x1 = x;
	((t_fdf *)param)->mouse->y1 = y;
	if (((t_fdf *)param)->mouse->left_key)
	{
		((t_fdf *)param)->vision->x_offset +=
			((t_fdf *)param)->mouse->x1 - ((t_fdf *)param)->mouse->x0;
		((t_fdf *)param)->vision->y_offset +=
			((t_fdf *)param)->mouse->y1 - ((t_fdf *)param)->mouse->y0;
		ft_draw_map(((t_fdf *)param));
	}
	else if (((t_fdf *)param)->mouse->right_key)
	{
		if (((t_fdf *)param)->mouse->x1 - ((t_fdf *)param)->mouse->x0 > 0)
			((t_fdf *)param)->vision->angle_y += 0.08;
		else if (((t_fdf *)param)->mouse->x1 - ((t_fdf *)param)->mouse->x0 < 0)
			((t_fdf *)param)->vision->angle_y -= 0.08;
		if (((t_fdf *)param)->mouse->y1 - ((t_fdf *)param)->mouse->y0 > 0)
			((t_fdf *)param)->vision->angle_x += 0.08;
		else if (((t_fdf *)param)->mouse->y1 - ((t_fdf *)param)->mouse->y0 < 0)
			((t_fdf *)param)->vision->angle_x -= 0.08;
		ft_draw_map(((t_fdf *)param));
	}
	return (0);
}
