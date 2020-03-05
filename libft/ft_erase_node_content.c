/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase_node_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:24:05 by lliza             #+#    #+#             */
/*   Updated: 2019/09/13 18:20:42 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_erase_node_content(void *node, size_t node_size)
{
	t_list *ptr;

	ptr = node;
	if (ptr)
		if (ptr->content_size == node_size)
		{
			free(ptr->content);
			ptr->content = NULL;
		}
}
