/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_two_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:21:40 by yliu              #+#    #+#             */
/*   Updated: 2024/01/24 17:05:32 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ope_two_node(t_lst **stack_a, t_lst **lst_procedure)
{
	if (get_int_value_of(*stack_a) > get_int_value_of((*stack_a)->next_p))
		operate_sa(stack_a, stack_a, lst_procedure);
	return ;
}
