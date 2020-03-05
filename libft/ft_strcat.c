/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:31:25 by lliza             #+#    #+#             */
/*   Updated: 2019/09/09 19:13:27 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *ptr;

	ptr = dest;
	while (*ptr)
		++ptr;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}
