/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_strategy(const char *arg, t_data *data)
{
	if (ft_strcmp(arg, "--simple") == 0)
		data->strategy = STRATEGY_SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		data->strategy = STRATEGY_MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		data->strategy = STRATEGY_COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		data->strategy = STRATEGY_ADAPTIVE;
	else if (ft_strcmp(arg, "--bench") == 0)
		data->bench_mode = 1;
	else
		return (0);
	return (1);
}

static int	count_numbers(int argc, char **argv)
{
	int		count;
	int		i;
	char	**split;
	int		j;

	count = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-' || ft_isdigit(argv[i][1])
			|| (argv[i][1] == '\0'))
		{
			split = ft_split(argv[i], ' ');
			j = 0;
			while (split && split[j])
				j++;
			count += j;
			free_split(split);
		}
		i++;
	}
	return (count);
}

static int	add_numbers_from_arg(char *arg, t_data *data, int *idx)
{
	char	**split;
	int		i;
	long	num;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		if (!is_valid_int(split[i]))
		{
			free_split(split);
			return (0);
		}
		num = ft_atol(split[i]);
		data->a->data[*idx] = (int)num;
		(*idx)++;
		data->a->size++;
		i++;
	}
	free_split(split);
	return (1);
}

static int	is_flag(const char *arg)
{
	if (ft_strncmp(arg, "--", 2) == 0 && !ft_isdigit(arg[2]))
		return (1);
	return (0);
}

int	parse_args(int argc, char **argv, t_data *data)
{
	int	i;
	int	idx;
	int	num_count;

	num_count = count_numbers(argc, argv);
	if (num_count == 0)
		return (0);
	data->a = stack_init(num_count);
	data->b = stack_init(num_count);
	if (!data->a || !data->b)
		return (0);
	i = 1;
	idx = 0;
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			if (!parse_strategy(argv[i], data))
				return (0);
		}
		else if (!add_numbers_from_arg(argv[i], data, &idx))
			return (0);
		i++;
	}
	return (!has_duplicates(data->a));
}
