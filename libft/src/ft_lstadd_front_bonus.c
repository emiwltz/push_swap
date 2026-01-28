/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:00:53 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:38:30 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*liste;
// 	char	s[14] = "allo les amis";
// 	char	s2[14] = "sima sel olla";

// 	liste = ft_lstnew(&s);
// 	printf("%p\n", liste);
// 	printf("%s\n", (char *)liste->content);
// 	printf("%p\n", liste->next);
// 	printf("\n");
// 	ft_lstadd_front(&liste, ft_lstnew(&s2));
// 	while (liste)
// 	{
// 		printf("address of node:%p\n", liste);
// 		printf("content of node:%s\n", (char *)liste->content);
// 		printf("address of next:%p\n", liste->next);
// 		printf("\n");
// 		liste = liste->next;
// 	}
// 	return (0);
// }
