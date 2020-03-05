/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:11:19 by lliza             #+#    #+#             */
/*   Updated: 2019/09/19 11:16:56 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *temp_origin;
	t_list *temp_new;

	new_lst = NULL;
	if (lst && f)
	{
		new_lst = f(lst);
		if (!new_lst)
			return (new_lst);
		temp_origin = lst;
		temp_new = new_lst;
		while (temp_origin->next)
		{
			temp_new->next = f(temp_origin->next);
			if (!temp_new->next)
				return (NULL);
			temp_origin = temp_origin->next;
			temp_new = temp_new->next;
		}
	}
	return (new_lst);
}
