/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:02:24 by lliza             #+#    #+#             */
/*   Updated: 2019/09/26 10:17:26 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		len;

	ptr = NULL;
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr)
	{
		ft_bzero(ptr, len + 1);
		if (s1)
			ptr = ft_strcpy(ptr, s1);
		if (s2)
			ptr = ft_strcat(ptr, s2);
		ptr[len] = '\0';
	}
	return (ptr);
}
