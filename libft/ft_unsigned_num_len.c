/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_num_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:54:57 by lliza             #+#    #+#             */
/*   Updated: 2019/11/26 16:54:58 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_unsigned_num_len(unsigned long long num, unsigned int base)
{
	size_t r;

	r = 0;
	while (num != 0)
	{
		r++;
		num /= base;
	}
	return (r);
}
