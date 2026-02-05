/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:26:59 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/05 15:36:50 by alemyre          ###   ########.fr       */
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

int	set_flags(char *str, t_ctx *ctx)
{
	if (str[0] == '-' && str[1] == '-')
	{
		if (set_algo(str, ctx))
			return (1);
	}
	if (!ft_strcmp((const char *)str, "--bench"))
	{
		ctx->bench_enabled = 1;
		ctx->bench_count += 1;
		return (1);
	}
	return (0);
}

int	*third_check(char **payload)
{
	size_t	i;
	int		*table;
	size_t	payload_count;

	i = 0;
	payload_count = count_payload(payload);
	table = malloc(sizeof(int) * payload_count);
	while (i < payload_count)
	{
		table[i] = ft_atoi(payload[i]);
		i++;
	}
	if (check_double(table, payload_count))
		return (NULL);
	return (table);
}

int	second_check(char **argv, int argc)
{
	size_t	i;
	char	**int_table;

	i = 0;
	int_table = clean_flags(argv, argc);
	while (int_table[i] != NULL)
	{
		if (!is_valid_digit(int_table[i]))
			return (1);
		i++;
	}
	if (!third_check(int_table))
		return (1);
	return (0);
}

t_stack	*initialize_stack_a(t_node *node)
{
	t_stack	*res;

	if (!node)
		return (NULL);
	res = lst_newstack(node);
	if (!res)
		return (NULL);
	return (res);
}

// maybe size_t for i?
int	first_check(char **argv, int argc, t_ctx ctx)
{
	int		i;
	t_stack	*stack_a;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		if (set_flags(argv[i], &ctx))
		{
			i++;
			continue ;
		}
		if (argv[i][0] == '\0')
			return (1);
		if (!arg_is_valid(argv[i]))
			return (1);
		if (!stack_a)
		{
			if (!(stack_a = initialize_stack_a(lst_newnode(argv[i]))))
				return (1);
		}
		else
			lst_addnodeback(lst_newnode(argv[i]), stack_a);
		i++;
	}
	if (ctx.flag_count > 1 || ctx.bench_count > 1)
		return (1);
	if (second_check(argv, argc))
		return (1);
	return (0);
}
