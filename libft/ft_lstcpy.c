/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:13:57 by lliza             #+#    #+#             */
/*   Updated: 2019/09/13 18:27:07 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstcpy(t_list *lst)
{
	t_list *lst_cpy;
	t_list *temp;
	t_list *origin;

	lst_cpy = NULL;
	if (lst)
	{
		lst_cpy = ft_lstnew(lst->content, lst->content_size);
		temp = lst_cpy;
		origin = lst;
		while (origin->next)
		{
			origin = origin->next;
			temp->next = ft_lstnew(origin->content, origin->content_size);
			if (!temp->next)
			{
				ft_lstdel(&lst_cpy, ft_erase_node_content);
				break ;
			}
			temp = temp->next;
		}
		temp = NULL;
		origin = NULL;
	}
	return (lst_cpy);
}
