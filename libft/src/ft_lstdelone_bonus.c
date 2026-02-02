/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:09:04 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/02 15:31:39 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*liste;

// 	liste = ft_lstnew(ft_strdup("yeah yeah"));
// 	printf("content of node:%s\n", (char *)liste->content);
// 	ft_lstdelone(liste, free);
// 	return (0);
// }
