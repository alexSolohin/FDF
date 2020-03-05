/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:48:50 by lliza             #+#    #+#             */
/*   Updated: 2020/02/05 15:44:21 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "libft.h"

void	ft_clear(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
}

int		ft_close(void *param)
{
	(void)param;
	exit(0);
}

int		ft_fdf_usage(void)
{
	ft_putendl("USAGE: ./fdf <path/to/map_file> \
[--set_colors color_top color_bottom] (print colors in hexadecimal)");
	exit(0);
}

int		ft_in_menu_button(int x, int y)
{
	if (y >= 0 && y < B_H)
		if (x >= 0 && x < MENU_W)
			return (1);
	return (0);
}

void	ft_find_z_range(t_fdf *fdf)
{
	int i;
	int j;
	int **map;

	i = 0;
	map = fdf->map;
	fdf->z_min = map[0][0];
	fdf->z_max = map[0][0];
	while (i < fdf->map_height)
	{
		j = 0;
		while (j < fdf->map_width)
		{
			if (map[i][j] > fdf->z_max)
				fdf->z_max = map[i][j];
			else if (map[i][j] < fdf->z_min)
				fdf->z_min = map[i][j];
			++j;
		}
		++i;
	}
}
