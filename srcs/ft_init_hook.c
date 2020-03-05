/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:17:00 by lliza             #+#    #+#             */
/*   Updated: 2020/01/16 14:47:21 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "ft_fdf_key_num.h"

int		ft_init_hook(t_fdf *fdf)
{
	mlx_hook(fdf->win, MOUSE_MOVE, 0, ft_mouse_move_rotate, fdf);
	mlx_hook(fdf->win, MOUSE_BUTTON_PRESS, 0, ft_mouse_key_press, fdf);
	mlx_hook(fdf->win, MOUSE_BUTTON_RELEASE, 0, ft_mouse_key_release, fdf);
	mlx_hook(fdf->win, KEY_BUTTON_PRESS, 0, ft_keyboard_hook, fdf);
	mlx_hook(fdf->win, ESC_BUTTON_PRESS, 0, ft_close, fdf);
	return (0);
}
