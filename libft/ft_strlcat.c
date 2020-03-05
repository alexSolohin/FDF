/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:15:19 by lliza             #+#    #+#             */
/*   Updated: 2019/09/13 19:38:30 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int			j;
	int			i;
	size_t		dst_len;
	size_t		src_len;

	j = 0;
	dst_len = 0;
	src_len = 0;
	while (dst[dst_len])
		dst_len++;
	while (src[src_len])
		src_len++;
	i = size - dst_len - 1;
	while (i-- > 0 && src[j])
	{
		dst[dst_len + j] = src[j];
		++j;
	}
	dst[dst_len + j] = '\0';
	return (dst_len > size ? (size + src_len) : (src_len + dst_len));
}
