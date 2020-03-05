/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:47:59 by lliza             #+#    #+#             */
/*   Updated: 2020/01/28 15:48:31 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "fdf.h"
#include "ft_get_next_line.h"
#include "ft_fdf_key_num.h"
#include <fcntl.h>
#include <math.h>

void	rotate_x_axis(int *y, int *z, double angle_x)
{
	int y_original;

	y_original = *y;
	*y = y_original * cos(angle_x) + *z * sin(angle_x);
	*z = *z * cos(angle_x) - y_original * sin(angle_x);
}

void	rotate_y_axis(int *x, int *z, double angle_y)
{
	int x_original;

	x_original = *x;
	*x = x_original * cos(angle_y) + *z * sin(angle_y);
	*z = *z * cos(angle_y) - x_original * sin(angle_y);
}

void	rotate_z_axis(int *x, int *y, int z)
{
	int	x_original;
	int y_original;

	x_original = *x;
	y_original = *y;
	*x = x_original * cos(z) - (y_original) * sin(z);
	*y = x_original * sin(z) + (y_original) * cos(z);
}
