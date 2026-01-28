/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:19:03 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:38:38 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	if (!lst || !f)
		return ;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}
// #include <stdio.h>

// void	ft_f(void *param)
// {
// 	char	*temp;

// 	temp = (char *)param;
// 	temp[0] = temp[0] - 32;
// }

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
// 	ft_lstiter(liste, ft_f);
// 	temp = liste;
// 	while (temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	return (0);
// }
