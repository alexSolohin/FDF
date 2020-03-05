/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:52:30 by lliza             #+#    #+#             */
/*   Updated: 2019/09/13 19:45:31 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrev(const char *s)
{
	int		len;
	char	*new_s;

	new_s = NULL;
	if (s)
	{
		len = ft_strlen(s);
		new_s = (char *)malloc(sizeof(char) * (len + 1));
		if (!new_s)
			return (NULL);
		new_s[len] = '\0';
		while (--len >= 0)
			new_s[len] = *s++;
	}
	return (new_s);
}
