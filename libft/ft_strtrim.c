/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:17:39 by lliza             #+#    #+#             */
/*   Updated: 2019/09/13 19:49:56 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strbegtrim(char const *s)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			++i;
		ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen(&s[i]) + 1));
		if (!ptr)
			return (NULL);
		ptr = ft_strcpy(ptr, &s[i]);
	}
	return (ptr);
}

char		*ft_strtrim(char const *s)
{
	char	*ptr;
	int		len;

	ptr = NULL;
	if (s)
	{
		ptr = ft_strbegtrim(s);
		if (!ptr)
			return (NULL);
		len = ft_strlen(ptr);
		if (ptr[len - 1] == ' ' || ptr[len - 1] == '\t' || ptr[len - 1] == '\n')
			ptr = ft_strrev(ft_strbegtrim(ft_strrev(ptr)));
	}
	return (ptr);
}
