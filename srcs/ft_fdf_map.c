/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:45:22 by lliza             #+#    #+#             */
/*   Updated: 2020/01/28 15:45:25 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_get_next_line.h"
#include "fdf.h"

static void		ft_free_strarr(char ***arr)
{
	int		i;
	char	*temp;

	i = 0;
	if ((*arr))
	{
		temp = (*arr)[i];
		if (!temp)
			exit(-1);
		while (temp)
		{
			temp = (*arr)[i + 1];
			free((*arr)[i]);
			i++;
		}
		free((*arr));
		(*arr) = NULL;
	}
}

static void		ft_get_map_size(char *file_name, t_fdf *fdf)
{
	int		fd;
	char	*temp;
	char	**temp_arr;

	fdf->map_width = 0;
	fdf->map_height = 0;
	temp_arr = NULL;
	if ((fd = open(file_name, O_RDONLY)) > 0)
	{
		while (ft_get_next_line(fd, &temp))
		{
			if (!fdf->map_height)
				temp_arr = ft_strsplit(temp, ' ');
			ft_strdel(&temp);
			fdf->map_height++;
		}
		ft_strdel(&temp);
		close(fd);
		if (!temp_arr || !*temp_arr)
			exit(-1);
		while (temp_arr[fdf->map_width])
			fdf->map_width++;
		ft_free_strarr(&temp_arr);
	}
}

static void		ft_init_maparr(int ***map, t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	if (!(*map = (int **)malloc(sizeof(int *) * fdf->map_height)))
		exit(-1);
	while (i < fdf->map_height)
	{
		if (!((*map)[i] = (int *)malloc(sizeof(int) * fdf->map_width)))
			exit(-1);
		j = 0;
		while (j < fdf->map_width)
			(*map)[i][j++] = 0;
		++i;
	}
}

static void		ft_compose_map_line(int *line, char **arr, t_fdf *fdf)
{
	int i;

	i = 0;
	if (line && arr)
		if (*arr)
			while (i < fdf->map_width)
			{
				line[i] = ft_atoi(arr[i]);
				++i;
			}
}

int				**ft_maparr(char *file_name, t_fdf *fdf)
{
	int		**map;
	int		fd;
	char	*temp;
	char	**temp2;
	int		i;

	i = 0;
	ft_get_map_size(file_name, fdf);
	ft_init_maparr(&map, fdf);
	if ((fd = open(file_name, O_RDONLY)) > 0)
	{
		while (i < fdf->map_height)
		{
			ft_get_next_line(fd, &temp);
			temp2 = ft_strsplit(temp, ' ');
			ft_compose_map_line(map[i], temp2, fdf);
			free(temp);
			ft_free_strarr(&temp2);
			++i;
		}
		close(fd);
	}
	else
		exit(-1);
	return (map);
}
