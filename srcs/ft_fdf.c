/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:24:44 by lliza             #+#    #+#             */
/*   Updated: 2020/02/05 15:56:57 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"

static int		ft_fdf_is_valid(char *file_name)
{
	int len;

	len = ft_strlen(file_name);
	if (len < 5)
		return (0);
	--len;
	return (file_name[len] == 'f' && file_name[len - 1] == 'd' &&
			file_name[len - 2] == 'f' && file_name[len - 3] == '.');
}

int				main(int ac, char **av)
{
	t_fdf		fdf;
	t_mouse		mouse;

	if (ac < 2)
		return (ft_fdf_usage());
	if (ft_fdf_is_valid(av[1]))
	{
		mouse.left_key = 0;
		mouse.right_key = 0;
		mouse.third_key = 0;
		ft_fdf_init(&fdf, ac, av, &mouse);
		ft_draw_map(&fdf);
		mlx_loop(fdf.mlx);
	}
	return (0);
}
