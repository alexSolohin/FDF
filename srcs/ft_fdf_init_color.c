/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_init_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:57:07 by lliza             #+#    #+#             */
/*   Updated: 2020/01/28 15:04:17 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		calculate_init_color\
	(int color_max, int color_min, float percent)
{
	int		r_max;
	int		g_max;
	int		b_max;
	int		color;

	r_max = color_max & RED;
	g_max = color_max & GREEN;
	b_max = color_max & BLUE;
	color = 0;
	color += ((int)((r_max - color_min & RED) ?
			(float)(r_max) * percent : RED) & RED);
	color += ((int)((g_max - color_min & GREEN) ?
			(float)(g_max) * percent : GREEN) & GREEN);
	color += ((int)((b_max - color_min & BLUE) ?
			(float)(b_max) * percent : BLUE) & BLUE);
	return (color);
}

void			ft_init_point_color(t_point *p, t_fdf *fdf)
{
	float	percent;

	if (p->rgb == 0)
	{
		if (p->z == fdf->z_min)
			p->rgb = fdf->color_zero;
		else if (p->z == fdf->z_max)
			p->rgb = fdf->color_max;
		else
		{
			percent = (float)(p->z - fdf->z_min) /
					(float)(fdf->z_max - fdf->z_min);
			p->rgb = calculate_init_color(fdf->color_max,
					fdf->color_zero, percent);
		}
	}
}
