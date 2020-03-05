/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:20:09 by lliza             #+#    #+#             */
/*   Updated: 2019/09/12 16:25:00 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstlen(t_list *head)
{
	size_t len;
	t_list *temp;

	len = 0;
	temp = head;
	if (temp)
	{
		++len;
		while (temp->next)
		{
			temp = temp->next;
			++len;
		}
	}
	return (len);
}
