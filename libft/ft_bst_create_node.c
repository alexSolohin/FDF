/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bst_create_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 11:11:15 by lliza             #+#    #+#             */
/*   Updated: 2019/09/30 11:21:08 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_bst_node	*ft_bst_create_node(int key, char *content)
{
	t_bst_node	*new_node;

	new_node = (t_bst_node *)malloc(sizeof(t_bst_node));
	if (new_node)
	{
		new_node->key = key;
		if (content)
			new_node->s_content = ft_strdup(content);
		else
			new_node->s_content = NULL;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return (new_node);
}
