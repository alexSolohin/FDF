/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:43:49 by lliza             #+#    #+#             */
/*   Updated: 2019/09/13 19:29:50 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			ch;
	const unsigned char		*ptr;

	ptr = s;
	ch = c;
	while (n-- > 0)
	{
		if (*ptr == ch)
			return ((void *)ptr);
		++ptr;
	}
	return (NULL);
}
