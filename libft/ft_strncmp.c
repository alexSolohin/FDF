/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:17:28 by lliza             #+#    #+#             */
/*   Updated: 2019/09/16 15:56:42 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (n)
	{
		while ((ptr1[i] || ptr2[i]) && i < n)
		{
			if (ptr1[i] != ptr2[i])
				break ;
			++i;
		}
		if (i == n)
			--i;
		return (ptr1[i] - ptr2[i]);
	}
	return (0);
}
