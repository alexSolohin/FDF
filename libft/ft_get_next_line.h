/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:54:54 by lliza             #+#    #+#             */
/*   Updated: 2020/02/05 17:10:01 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# define BUFF_SIZE 512
# include "libft.h"

int				ft_get_next_line(const int fd, char **line);
typedef struct	s_basic_info
{
	t_bst_node		*tree;
	int				curr_len;
	t_bst_node		*curr;
	int				not_done;
	char			*temp;

}				t_base;
#endif
