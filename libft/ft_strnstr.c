/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:54:10 by lliza             #+#    #+#             */
/*   Updated: 2019/09/16 16:01:54 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size;
	size_t	n_size;
	size_t	i;

	if (*haystack)
	{
		i = 0;
		size = ft_strlen(haystack);
		n_size = ft_strlen(needle);
		if (!n_size)
			return ((char *)haystack);
		if (n_size > size)
			return (NULL);
		while (haystack[i] && (i + n_size) <= len)
		{
			if (haystack[i] == *needle)
				if (!ft_strncmp(&haystack[i], needle, n_size))
					return ((char *)&haystack[i]);
			i++;
		}
	}
	return (haystack == needle ? (char *)needle : NULL);
}
