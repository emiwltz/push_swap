/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:23:29 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/21 12:46:41 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"


typedef struct s_node{
  int	value;
  int	rank;
  struct s_node *next;
}t_node;

typedef enum e_algo{
  ALGO_SIMPLE,
  ALGO_MEDIUM,
  ALGO_COMPLEX,
  ALGO_ADAPTATIVE,
}t_algo;

typedef struct s_stack{
  t_node *head;
  t_node *tail;
  int	size;
}t_stack;

#endif

