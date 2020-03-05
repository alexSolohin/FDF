/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:45:55 by lliza             #+#    #+#             */
/*   Updated: 2020/02/05 18:50:01 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "libft.h"

static t_button		*ft_init_button(void)
{
	t_button *b;

	if (!(b = (t_button *)malloc(sizeof(t_button))))
		exit(-1);
	b->y_offset = 0;
	b->text = NULL;
	b->next = NULL;
	return (b);
}

t_button			*ft_init_buttons(void)
{
	t_button	*head;
	t_button	*temp;
	int			i;
	char		*ptr;
	char		*temp_ptr;

	i = -1;
	head = ft_init_button();
	temp = head;
	ptr = "MENU|LEFT BUTTON or ARROWS:|move|RIGHT BUTTON or 2,4,6,8:|rotate|"
	"SCROLL or -/+:|zoom|I / P:|change projection|(^_^) SMILE:|have fun";
	while (++i < BUTTONS_NUM)
	{
		if (!(temp_ptr = ft_strchr(ptr, '|')))
			temp_ptr = ft_strchr(ptr, '\0');
		if (!(temp->text = (char *)malloc(sizeof(char) * (temp_ptr - ptr))))
			exit(-1);
		ft_bzero(temp->text, (temp_ptr - ptr + 1));
		ft_strncpy(temp->text, ptr, (temp_ptr - ptr));
		temp->y_offset = B_H * i;
		ptr = *temp_ptr == '|' ? temp_ptr + 1 : temp_ptr;
		temp->next = i < BUTTONS_NUM - 1 ? ft_init_button() : NULL;
		temp = temp->next;
	}
	return (head);
}

static void			ft_init_menu_folded(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 110, 10, 0xFFFFFF, "MENU");
}

void				ft_init_menu_button_bg(t_fdf *fdf)
{
	int y;
	int x;
	int i;

	y = 0;
	i = 0;
	while (y < B_H)
	{
		x = 0;
		while (x < MENU_W)
		{
			i = (y * fdf->line_size) + (x * 4);
			if (i >= 0 && ft_in_menu_button(x, y))
				*((int *)&fdf->pixels_arr[i]) = 0x5500;
			++x;
		}
		++y;
	}
}

void				ft_init_menu(t_fdf *fdf)
{
	t_button	*b_ptr;
	int			s_x_offset;
	int			i;

	i = 0;
	if (fdf->menu->folded)
	{
		ft_init_menu_folded(fdf);
		return ;
	}
	b_ptr = fdf->menu->buttons;
	while (b_ptr)
	{
		if (i == 0)
			s_x_offset = 110;
		else
			s_x_offset = i % 2 ? 20 : 90;
		mlx_string_put(fdf->mlx, fdf->win, s_x_offset,
	b_ptr->y_offset + 10, i == 0 ? 0xFFFFFF : B_TEXT_COLOR, b_ptr->text);
		b_ptr = b_ptr->next;
		++i;
	}
}
