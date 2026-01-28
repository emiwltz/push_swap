/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:27:24 by alemyre           #+#    #+#             */
/*   Updated: 2025/12/02 13:44:17 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_words(char *s, char c)
{
	size_t	i;
	int		arr;

	i = 0;
	arr = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			arr++;
		i++;
	}
	return (arr);
}

static int	ft_free(char **res, int arr)
{
	while (arr >= 0)
		free(res[arr--]);
	free(res);
	return (0);
}

static int	ft_make_word(size_t *index, char **res, char *s)
{
	size_t	k;

	k = 0;
	while (k < index[1])
	{
		res[index[2]][k] = s[k + index[0]];
		k++;
	}
	res[index[2]++][k] = '\0';
	return (index[2]);
}

static int	ft_iterate_s(char *s, size_t *index, char c, char **res)
{
	index[1] = 0;
	while (s[index[0] + index[1]] && s[index[0] + index[1]] != c)
		index[1]++;
	if (index[1] != 0)
	{
		res[index[2]] = malloc(sizeof(char) * (index[1] + 1));
		if (!res[index[2]])
			return (ft_free(res, index[2] - 1));
		ft_make_word(index, res, (char *)s);
	}
	if (!index[1])
		index[0]++;
	else
		index[0] += index[1];
	return (index[0]);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	index[3];

	index[0] = 0;
	index[2] = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_count_words((char *)s, c) + 1));
	if (!res)
		return (NULL);
	while (index[0] < ft_strlen(s))
	{
		index[0] = ft_iterate_s((char *)s, index, c, res);
		if (!index[0])
			return (NULL);
	}
	res[index[2]] = NULL;
	return (res);
}
