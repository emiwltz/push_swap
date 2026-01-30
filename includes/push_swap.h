/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:23:29 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/29 11:47:29 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"

#define ERR_MSG "Error\n"
#define FLAG_BENCH "--bench"
#define FLAG_SIMPLE "--simple"
#define FLAG_MEDIUM "--medium"
#define FLAG_COMPLEX "--complex"
#define FLAG_ADAPTIVE "--adaptive"

#include <stdbool.h>
#include <limits.h>

typedef struct s_node{
  int	value;
  int	rank;
  struct s_node *next;
}t_node;

typedef enum e_algo{
  ALGO_UNSET,
  ALGO_SIMPLE,
  ALGO_MEDIUM,
  ALGO_COMPLEX,
  ALGO_ADAPTIVE,
}t_algo;

typedef struct s_ctx{
  bool bench_enabled;
  t_algo algo;
  int flag_count;
  int bench_count;
}t_ctx;

typedef struct s_stack{
  t_node *head;
  t_node *tail;
  size_t	size;
}t_stack;

void	error_msg(void);
int	ft_strcmp(const char *str1, const char *str2);
int	is_digit_string(char *s);
int	first_check(char **argv, int argc, t_ctx ctx);
char	**set_flags(char *str, t_ctx *ctx);
int	arg_is_valid(char *s);
void	print_error(void);
int	is_valid_digit(char *s);
char	**clean_flags(char **argv, int argc);
int	count_payload(char **payload);
int	*third_check(char **payload);
long	ft_atol(const char *str);
int only_spaces(char *s);
bool  is_a_flag(char *s);
#endif
