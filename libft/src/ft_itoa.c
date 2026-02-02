/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:57:38 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/02 15:31:29 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_intlen(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*copy(char *result, size_t len, long nbr)
{
	while (nbr != 0)
	{
		result[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	len;
	char	*result;

	nbr = n;
	len = ft_intlen(nbr);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	return (copy(result, len, nbr));
}

//int main(void)
//{
//    char *s = ft_itoa(55);
//    printf("%s\n", s);
//    free(s);
//}
//
