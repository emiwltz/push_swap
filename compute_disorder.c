/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 21:49:23 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/03 21:53:15 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	compute_disorder(stack a)
{
	size_t	mistakes;
	size_t	total_pairs;
	size_t	i;
	size_t	j;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < (ft_strlen(a) - 1))
	{
		j = i + 1;
		while (j < ft_strlen(a) - 1)
		{
			total_pairs++;
			if (a[i] > a[j])
				mistakes++;
		}
	}
	return (mistakes / total_pairs)
}
