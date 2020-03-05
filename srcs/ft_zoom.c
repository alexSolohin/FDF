/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:54:48 by lliza             #+#    #+#             */
/*   Updated: 2020/01/28 15:54:50 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_fdf_key_num.h"

void	ft_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == MAIN_PAD_PLUS ||
		keycode == NUM_PAD_PLUS ||
		keycode == MOUSE_SCROLL_UP)
		fdf->vision->zoom++;
	else if (keycode == MAIN_PAD_MINUS ||
			keycode == NUM_PAD_MINUS ||
			keycode == MOUSE_SCROLL_DOWN)
		fdf->vision->zoom--;
}

void	ft_divisior(int keycode, t_fdf *fdf)
{
	if (keycode == MAIN_PAD_MORE)
		fdf->vision->z_divisior += 0.2;
	else if (keycode == MAIN_PAD_LESS)
		fdf->vision->z_divisior -= 0.2;
	if (fdf->vision->z_divisior <= 0.2)
		fdf->vision->z_divisior = 0.2;
	else if (fdf->vision->z_divisior > 10)
		fdf->vision->z_divisior = 10;
}
