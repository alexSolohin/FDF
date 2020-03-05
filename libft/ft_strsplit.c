/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:07:23 by lliza             #+#    #+#             */
/*   Updated: 2019/09/19 12:19:10 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_cw_delimiter(char const *s, char c)
{
	size_t		count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (count);
}

static void		make_arr(char ***arr, char const *s, char c, size_t len)
{
	size_t	i;
	int		j;

	j = -1;
	if (arr && s && c)
		while ((size_t)++j < len)
		{
			i = 0;
			while (*s == c)
				++s;
			while (*s && *s != c)
				++s && ++i;
			(*arr)[j] = malloc(sizeof(char) * i + 1);
			if (!(*arr)[j])
			{
				while (j >= 0)
					free((*arr)[--j]);
				free(arr);
				arr = NULL;
				return ;
			}
			(*arr)[j] = ft_strncpy((*arr)[j], s - i, i);
			(*arr)[j][i] = '\0';
		}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	len;

	arr = NULL;
	if (s && c)
	{
		len = ft_cw_delimiter(s, c);
		arr = (char **)malloc(sizeof(char *) * (len + 1));
		if (!arr)
			return (NULL);
		make_arr(&arr, s, c, len);
		if (arr)
			arr[len] = NULL;
	}
	return (arr);
}
