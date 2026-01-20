/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_split.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ewaltz <ewaltz@student.42lyon.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/18 11:08:40 by ewaltz			   #+#	  #+#			  */
/*	 Updated: 2025/11/24 14:16:30 by ewaltz			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_word_dup(char const *s, size_t start, size_t end)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

static void	ft_free_all(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	**fill_tab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			tab[j] = ft_word_dup(s, start, i);
			if (!tab[j])
				return (ft_free_all(tab), NULL);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!tab)
		return (NULL);
	return (fill_tab(tab, s, c));
}
