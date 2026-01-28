/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:09:04 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:38:35 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
