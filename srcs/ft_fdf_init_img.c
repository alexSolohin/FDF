/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_init_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:23:40 by rmaxima           #+#    #+#             */
/*   Updated: 2020/01/28 16:27:39 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"

int		ft_fdf_init_img(t_fdf *fdf)
{
	int endian;

	if (!(fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT)))
		exit(-1);
	fdf->bits_per_pixel = 32;
	fdf->line_size = fdf->bits_per_pixel * WIDTH;
	endian = ENDIAN;
	fdf->pixels_arr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel,
		&fdf->line_size, &endian);
	return (0);
}
