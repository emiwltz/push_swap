/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_next_line_simple(int fd)
{
	char	*line;
	char	c;
	int		i;
	int		ret;

	line = (char *)malloc(sizeof(char) * 5);
	if (!line)
		return (NULL);
	i = 0;
	ret = read(fd, &c, 1);
	while (ret > 0 && c != '\n' && i < 4)
	{
		line[i++] = c;
		ret = read(fd, &c, 1);
	}
	if (ret <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

static int	execute_operation(t_data *data, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		op_sa(data, 0);
	else if (ft_strcmp(op, "sb") == 0)
		op_sb(data, 0);
	else if (ft_strcmp(op, "ss") == 0)
		op_ss(data, 0);
	else if (ft_strcmp(op, "pa") == 0)
		op_pa(data, 0);
	else if (ft_strcmp(op, "pb") == 0)
		op_pb(data, 0);
	else if (ft_strcmp(op, "ra") == 0)
		op_ra(data, 0);
	else if (ft_strcmp(op, "rb") == 0)
		op_rb(data, 0);
	else if (ft_strcmp(op, "rr") == 0)
		op_rr(data, 0);
	else if (ft_strcmp(op, "rra") == 0)
		op_rra(data, 0);
	else if (ft_strcmp(op, "rrb") == 0)
		op_rrb(data, 0);
	else if (ft_strcmp(op, "rrr") == 0)
		op_rrr(data, 0);
	else
		return (0);
	return (1);
}

static int	read_and_execute(t_data *data)
{
	char	*line;

	line = get_next_line_simple(0);
	while (line)
	{
		if (!execute_operation(data, line))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line_simple(0);
	}
	return (1);
}

static int	has_only_flags_checker(int argc, char **argv)
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
	if (has_only_flags_checker(argc, argv))
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
	if (!read_and_execute(data))
		error_exit(data);
	if (stack_is_sorted(data->a) && data->b->size == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	data_free(data);
	return (0);
}
