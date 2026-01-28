/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:16:00 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:38:24 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		new->next = *lst;
		*lst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*liste;
// 	t_list	*temp;
// 	t_list	*last;

// 	liste = ft_lstnew("greetings");
// 	ft_lstadd_front(&liste, ft_lstnew("y0"));
// 	ft_lstadd_front(&liste, ft_lstnew("you are the best"));
// 	temp = liste;
// 	while (temp)
// 	{
// 		printf("content of node:%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	last = ft_lstnew("im last");
// 	ft_lstadd_back(&liste, last);
// 	printf("\nnew liste\n");
// 	temp = liste;
// 	while (temp)
// 	{
// 		printf("content of node:%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	return (0);
// }
