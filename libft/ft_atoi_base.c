/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:05:25 by lliza             #+#    #+#             */
/*   Updated: 2019/12/23 15:17:35 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isatof(char c)
{
	return ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

long long		ft_atoi_base(const char *str, int base)
{
	long long	r;
	int			is_negative;

	is_negative = 0;
	r = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			++is_negative;
	}
	while (ft_isdigit(*str) || ft_isatof(*str))
	{
		r = r * base + (ft_isdigit(*str) ?
			(*str - '0') : (10 + (ft_toupper(*str) - 'A')));
		++str;
	}
	r = is_negative ? -r : r;
	return (r);
}
