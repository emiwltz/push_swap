/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:32:35 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:38:33 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*n;

	temp = *lst;
	if (!lst || !del)
		return ;
	while (temp)
	{
		n = temp->next;
		ft_lstdelone(temp, del);
		temp = n;
	}
	*lst = NULL;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*liste;
// 	t_list	*temp;

// 	liste = ft_lstnew(ft_strdup("y0y0y0"));
// 	ft_lstadd_back(&liste, ft_lstnew(ft_strdup("number 1")));
// 	ft_lstadd_back(&liste, ft_lstnew(ft_strdup("numero dos")));
// 	temp = liste;
// 	while (temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	ft_lstclear(&liste, free);
// 	return (0);
// }
