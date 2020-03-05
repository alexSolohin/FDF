/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bst_insert_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 11:12:51 by lliza             #+#    #+#             */
/*   Updated: 2019/09/30 11:21:33 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bst_insert_node(t_bst_node **root, int key, char *content)
{
	if (!(*root))
		*root = ft_bst_create_node(key, content);
	if ((*root)->key > key)
		ft_bst_insert_node(&((*root)->left), key, content);
	if ((*root)->key < key)
		ft_bst_insert_node(&((*root)->right), key, content);
}
