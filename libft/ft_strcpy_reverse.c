/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:30:28 by lliza             #+#    #+#             */
/*   Updated: 2019/11/21 17:33:32 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy_reverse(char *dest, char *src)
{
	int		len_src;

	len_src = ft_strlen(src);
	while (len_src > 0)
	{
		*dest++ = *(src + len_src - 1);
		--len_src;
	}
}
