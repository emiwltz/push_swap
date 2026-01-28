/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:01:56 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:38:48 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*temp;

	temp = lst;
	i = 0;
	if (!temp)
		return (i);
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*liste;
// 	t_list	*temp;
// 	char	s[14] = "allo les amis";
// 	char	s2[14] = "sima sel olla";
// 	int		length;

// 	length = 0;
// 	liste = ft_lstnew(&s);
// 	printf("%p\n", liste);
// 	printf("%s\n", (char *)liste->content);
// 	printf("%p\n\n", liste->next);
// 	ft_lstadd_front(&liste, ft_lstnew(&s2));
// 	ft_lstadd_front(&liste, ft_lstnew("y0"));
// 	temp = liste;
// 	while (temp)
// 	{
// 		printf("address of node:%p\n", temp);
// 		printf("content of node:%s\n", (char *)temp->content);
// 		printf("address of next:%p\n", temp->next);
// 		printf("\n");
// 		temp = temp->next;
// 	}
// 	length = ft_lstsize(liste);
// 	printf("length of liste:%d\n", length);
// 	return (0);
// }