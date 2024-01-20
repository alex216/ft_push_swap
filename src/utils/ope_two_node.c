/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_two_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:21:40 by yliu              #+#    #+#             */
/*   Updated: 2024/01/20 16:33:15 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ope_two_node(t_lst **stack_a, t_lst **lst_procedure)
{
	operate_sa(stack_a, stack_a, lst_procedure);
	return ;
}
