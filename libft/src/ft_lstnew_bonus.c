/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:52:29 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:38:46 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*liste;
// 	t_list	*n;
// 	void	*ans;
// 	char	s[14] = "allo les amis";

// 	liste = ft_lstnew(&s);
// 	ans = liste->content;
// 	n = liste->next;
// 	printf("%s\n", (char *)ans);
// 	printf("%p\n", n);
// 	return (0);
// }