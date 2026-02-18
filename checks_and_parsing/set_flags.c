/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:26:59 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/17 10:45:16 by ewaltz           ###   ########.fr       */
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

t_stack	*initialize_stack(t_node *node)
{
	t_stack	*res;

	if (!node)
		return (NULL);
	res = lst_newstack(node);
	if (!res)
		return (NULL);
	return (res);
}

int	clear_split(char **numbers)
{
	size_t	i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (0);
}

int	populate_stack_a(char *value, t_stack **stack_a)
{
	size_t	i;
	char	**numbers;
	t_node	*node;

	numbers = ft_split((const char *)value, ' ');
	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i])
	{
		if (is_valid_digit(numbers[i]))
		{
			if (!(node = lst_newnode(numbers[i])))
				return (clear_split(numbers));
			if (*stack_a)
				lst_addnodeback(node, stack_a);
			else if (!(*stack_a = initialize_stack(node)))
				return (clear_split(numbers));
		}
		else
			return (clear_split(numbers));
		i++;
	}
	if (!check_double(stack_a))
		return (clear_split(numbers));
	clear_split(numbers);
	return (1);
}

// maybe size_t for i?
int	first_check(char **argv, int argc, t_ctx **ctx, t_stack **stack_a)
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
			return (1);
		if (!arg_is_valid(argv[i]))
			return (1);
		if (!populate_stack_a(argv[i], stack_a))
			return (1);
		set_ranks(stack_a);
		i++;
		numbers++;
	}
	if ((*ctx)->flag_count > 1 || (*ctx)->bench_count > 1 || numbers <= 0)
		return (1);
	return (0);
}
