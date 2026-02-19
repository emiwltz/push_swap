/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:26:59 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/19 13:25:12 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_algo(char *flag, t_ctx *ctx)
{
	if (!ft_strcmp(FLAG_SIMPLE, flag))
	{
		ctx->algo = ALGO_SIMPLE;
		ctx->flag_count += 1;
		return (1);
	}
	else if (!ft_strcmp(FLAG_MEDIUM, flag))
	{
		ctx->algo = ALGO_MEDIUM;
		ctx->flag_count += 1;
		return (1);
	}
	else if (!ft_strcmp(FLAG_COMPLEX, flag))
	{
		ctx->algo = ALGO_COMPLEX;
		ctx->flag_count += 1;
		return (1);
	}
	else if (!ft_strcmp(FLAG_ADAPTIVE, flag))
	{
		ctx->algo = ALGO_ADAPTIVE;
		ctx->flag_count += 1;
		return (1);
	}
	return (0);
}

int	set_flags(char *str, t_ctx **ctx)
{
	if (str[0] == '-' && str[1] == '-')
	{
		if (set_algo(str, *ctx))
			return (1);
	}
	if (!ft_strcmp((const char *)str, "--bench"))
	{
		(*ctx)->bench_enabled = 1;
		(*ctx)->bench_count += 1;
		return (1);
	}
	return (0);
}

int	iterate_args(char **argv, int argc, t_ctx **ctx, t_stack **stack_a)
{
	int	i;
	int	numbers;

	i = 1;
	numbers = 0;
	while (i < argc)
	{
		if (set_flags(argv[i], ctx))
		{
			i++;
			continue ;
		}
		if (argv[i][0] == '\0')
			return (0);
		if (!arg_is_valid(argv[i]))
			return (0);
		if (!populate_stack(argv[i], stack_a))
			return (0);
		set_ranks(stack_a);
		i++;
		numbers++;
	}
	if ((*ctx)->flag_count > 1 || (*ctx)->bench_count > 1 || numbers <= 0)
		return (0);
	return (1);
}
