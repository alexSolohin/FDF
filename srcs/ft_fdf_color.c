/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:08:23 by lliza             #+#    #+#             */
/*   Updated: 2020/02/05 18:47:47 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static int	calculate_color(int color_max, int color_min, float percent)
{
	int		color;

	color = 0;
	color += (int)((1 - percent) * (color_min & RED) +
			(color_max & RED) * percent) & RED;
	color += (int)((1 - percent) * (color_min & GREEN) +
			(color_max & GREEN) * percent) & GREEN;
	color += (int)((1 - percent) * (color_min & BLUE) +
			(color_max & BLUE) * percent) & BLUE;
	return (color);
}

int			calculate_p_color
	(t_fdf *fdf, t_point *start, t_point *end, t_point *curr)
{
	float	percent;
	int		color;

	color = 0;
	if (FT_ABS(curr->x - start->x) > FT_ABS(curr->y - start->y))
		percent = (float)(curr->x - start->x) / (float)(end->x - start->x);
	else
		percent = (float)(curr->y - start->y) / (float)(end->y - start->y);
	color = calculate_color(end->rgb, start->rgb, percent);
	if (fdf->color_inversion)
		color = 0xFFFFFF - color;
	if (!fdf->disco_off)
		color += fdf->disco;
	return (color);
}
