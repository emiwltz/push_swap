/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:23:29 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/23 14:49:52 by ewaltz           ###   ########.fr       */
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
int	is_not_digit_string(char *s);
void	parsing(char **argv, int argc, t_ctx ctx);
char	**set_flags(char *str, t_ctx *ctx);
int	is_mixed(char *s);
#endif
