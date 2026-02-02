/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_sort(t_data *data)
{
	if (data->strategy == STRATEGY_SIMPLE)
		sort_simple(data);
	else if (data->strategy == STRATEGY_MEDIUM)
		sort_medium(data);
	else if (data->strategy == STRATEGY_COMPLEX)
		sort_complex(data);
	else
		sort_adaptive(data);
}

static int	has_only_flags(int argc, char **argv)
{
	int	i;
	int	found_number;

	found_number = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-' || ft_isdigit(argv[i][1])
			|| (argv[i][1] == '\0' && argv[i][0] != '-'))
		{
			if (argv[i][0] != '\0')
				found_number = 1;
		}
		else if (ft_strncmp(argv[i], "--", 2) != 0)
		{
			found_number = 1;
		}
		i++;
	}
	return (!found_number);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	if (has_only_flags(argc, argv))
		return (0);
	data = data_init();
	if (!data)
		return (1);
	if (!parse_args(argc, argv, data))
		error_exit(data);
	if (data->a->size == 0)
	{
		data_free(data);
		return (0);
	}
	data->disorder = compute_disorder(data->a);
	execute_sort(data);
	if (data->bench_mode)
		print_benchmark(data);
	data_free(data);
	return (0);
}
