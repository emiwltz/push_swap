/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:50:59 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:38:43 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*res;
	void	*content;

	res = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, node);
		lst = lst->next;
	}
	return (res);
}
// #include <stdio.h>

// void	*ft_f(void *param)
// {
// 	char	*temp;

// 	temp = (char *)param;
// 	temp[3] = temp[3] + 2;
// 	return (param);
// }
// int	main(void)
// {
// 	t_list	*liste;
// 	t_list	*temp;
// 	t_list	*new;

// 	liste = ft_lstnew(ft_strdup("y0y0y0"));
// 	ft_lstadd_back(&liste, ft_lstnew(ft_strdup("number 1")));
// 	ft_lstadd_back(&liste, ft_lstnew(ft_strdup("numero dos")));
// 	temp = liste;
// 	while (temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	new = ft_lstmap(liste, ft_f, free);
// 	temp = new;
// 	while (temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	return (0);
// }
