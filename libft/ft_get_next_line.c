/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:54:43 by lliza             #+#    #+#             */
/*   Updated: 2019/09/30 11:19:46 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_get_next_line.h"
#include <unistd.h>

static int		has_lf(char *s)
{
	int i;

	i = 0;
	if (s)
		while (s[i])
			if (s[i++] == '\n')
				return (i);
	return (0);
}

static int		write_to_line(char **line, t_base bs, int fd)
{
	int		len;

	bs.curr = ft_bst_find_node(bs.tree, fd);
	len = has_lf(bs.curr->s_content);
	bs.curr_len = ft_strlen(bs.curr->s_content);
	*line = ft_strsub(bs.curr->s_content, 0, (len ? len - 1 : bs.curr_len));
	ft_strcpy(bs.curr->s_content,
		bs.curr->s_content + (len ? len : bs.curr_len));
	return (bs.curr_len);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_base		bs = { NULL, 0, NULL, 0, NULL };
	char				buff[BUFF_SIZE + 1];

	if (fd < 0 || !line)
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	while ((bs.not_done = read(fd, buff, BUFF_SIZE)))
	{
		if (bs.not_done < 0)
			return (-1);
		if ((bs.curr = ft_bst_find_node(bs.tree, fd)))
		{
			bs.temp = bs.curr->s_content;
			bs.curr->s_content = ft_strjoin(bs.temp, buff);
			free(bs.temp);
		}
		else
			ft_bst_insert_node(&bs.tree, fd, buff);
		ft_bzero(buff, BUFF_SIZE);
		if (!bs.not_done || has_lf((bs.curr ? bs.curr :
			ft_bst_find_node(bs.tree, fd))->s_content))
			break ;
	}
	bs.curr_len = write_to_line(line, bs, fd);
	return (bs.not_done ? 1 : !!bs.curr_len);
}
