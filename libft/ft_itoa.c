/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:59:45 by lliza             #+#    #+#             */
/*   Updated: 2019/09/17 15:36:26 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_numlen(int n)
{
	long int	num;
	int			count;

	num = n;
	count = 1;
	if (n < 0)
		num = -num;
	while (num >= 10)
	{
		count++;
		num /= 10;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		num;
	int		len;
	int		is_positive;

	is_positive = 1;
	num = n;
	len = num < 0 ? ft_numlen(n) + 1 : ft_numlen(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n == 0)
		s[0] = '0';
	if (num < 0)
	{
		is_positive = -1;
		*s = '-';
	}
	while (num)
	{
		s[--len] = (num % 10) * is_positive + '0';
		num /= 10;
	}
	return (s);
}
