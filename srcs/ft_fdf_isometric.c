/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_isometric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:26:21 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/05 15:35:11 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "fdf.h"

void		isometric(int *x, int *y, double z)
{
	double x_original;

	x_original = (double)*x;
	*x = (x_original - (double)*y) * cos(0.46373398);
	*y = (x_original + (double)*y) * sin(0.46373398) - z;
}

t_point		projection(t_point p, t_fdf *fdf)
{
	p.x *= fdf->vision->zoom;
	p.y *= fdf->vision->zoom;
	p.z *= fdf->vision->zoom / fdf->vision->z_divisior;
	p.x -= ((fdf->map_width - 1) * fdf->vision->zoom) / 2;
	p.y -= ((fdf->map_height - 1) * fdf->vision->zoom) / 2;
	rotate_x_axis(&p.y, &p.z, fdf->vision->angle_x);
	rotate_y_axis(&p.x, &p.z, fdf->vision->angle_y);
	rotate_z_axis(&p.x, &p.z, fdf->vision->angle_z);
	if (fdf->projection == ISO)
		isometric(&(p.x), &(p.y), p.z);
	p.x += WIDTH / 2 + fdf->vision->x_offset;
	p.y += HEIGHT / 2 + fdf->vision->y_offset;
	return (p);
}

t_vision	*ft_vision(t_fdf *fdf)
{
	t_vision *vision;

	if (!(vision = (t_vision *)malloc(sizeof(t_vision))))
		exit(-1);
	vision->zoom = WIDTH / fdf->map_width / 2;
	vision->angle_x = 0;
	vision->angle_y = 0;
	vision->angle_z = 0;
	vision->z_divisior = 1;
	vision->x_offset = 0;
	vision->y_offset = 0;
	return (vision);
}
