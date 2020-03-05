/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:44:35 by lliza             #+#    #+#             */
/*   Updated: 2019/09/11 12:59:38 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ptr;

	ptr = NULL;
	if (s)
	{
		ptr = (char *)malloc(sizeof(char) * len + 1);
		if (ptr)
		{
			ptr = ft_strncpy(ptr, &s[start], len);
			ptr[len] = '\0';
		}
	}
	return (ptr);
}
