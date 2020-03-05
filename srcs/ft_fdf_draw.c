/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:03:03 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/05 18:46:01 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include "math.h"

static void		ft_pixel_put(t_fdf *fdf, int x, int y, int rgb)
{
	int	i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (!fdf->menu->folded)
			if (x >= 0 && x < MENU_W && y >= B_H && y < MENU_H)
				rgb = MENU_BG;
		i = (y * fdf->line_size) + (x * 4);
		if (i >= 0 && !ft_in_menu_button(x, y))
		{
			if (fdf->color_inversion)
				*((int *)&fdf->pixels_arr[i]) = rgb;
			else if (*((int *)&fdf->pixels_arr[i]) == 0)
				*((int *)&fdf->pixels_arr[i]) = rgb;
		}
	}
}

static void		ft_draw_line(t_point p0, t_point p1, t_fdf *fdf)
{
	const int	deltax = FT_ABS(p1.x - p0.x);
	const int	deltay = FT_ABS(p1.y - p0.y);
	const int	signx = p0.x < p1.x ? 1 : -1;
	const int	signy = p0.y < p1.y ? 1 : -1;
	t_point		start;

	fdf->error = deltax - deltay;
	start = p0;
	ft_pixel_put(fdf, p1.x, p1.y, calculate_p_color(fdf, &start, &p1, &p0));
	while (p0.x != p1.x || p0.y != p1.y)
	{
		ft_pixel_put(fdf, p0.x, p0.y, calculate_p_color(fdf, &start, &p1, &p0));
		fdf->error2 = fdf->error * 2;
		if (fdf->error2 > -deltay)
		{
			fdf->error -= deltay;
			p0.x += signx;
		}
		if (fdf->error2 < deltax)
		{
			fdf->error += deltax;
			p0.y += signy;
		}
	}
}

static t_point	ft_point(int x, int y, t_fdf *fdf)
{
	t_point p;

	p.x = x;
	p.y = y;
	p.z = fdf->map[y][x];
	p.rgb = 0;
	ft_init_point_color(&p, fdf);
	return (p);
}

static void		ft_draw_loop(t_fdf *fdf, int *x, int *y)
{
	while (*y < fdf->map_height - 1)
	{
		*x = 0;
		while (*x < fdf->map_width - 1)
		{
			ft_draw_line(projection(ft_point(*x, *y, fdf), fdf),
					projection(ft_point(*x + 1, *y, fdf), fdf), fdf);
			ft_draw_line(projection(ft_point(*x, *y, fdf), fdf),
					projection(ft_point(*x, *y + 1, fdf), fdf), fdf);
			++(*x);
		}
		ft_draw_line(projection(ft_point(*x, *y, fdf), fdf),
			projection(ft_point(*x, *y + 1, fdf), fdf), fdf);
		++(*y);
	}
}

void			ft_draw_map(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	ft_bzero(fdf->pixels_arr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	ft_draw_loop(fdf, &x, &y);
	x = 0;
	while (x < fdf->map_width - 1)
	{
		ft_draw_line(projection(ft_point(x, y, fdf), fdf),
				projection(ft_point(x + 1, y, fdf), fdf), fdf);
		x++;
	}
	ft_init_menu_button_bg(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	ft_init_menu(fdf);
}
