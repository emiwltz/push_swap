/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:21:42 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:38:41 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*n;

	n = lst;
	if (!lst)
		return (NULL);
	while (n->next)
	{
		n = n->next;
	}
	return (n);
}
// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*liste;
// 	t_list	*temp;
// 	t_list	*last;
// 	char	s[14] = "allo les amis";
// 	char	s2[14] = "sima sel olla";

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
// 	last = ft_lstlast(liste);
// 	printf("\naddress of last node:%p\n", last);
// 	return (0);
// }
