/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_five_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:19:28 by yliu              #+#    #+#             */
/*   Updated: 2024/01/13 19:32:46 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

ssize_t	ope_five_node(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	operate_pb(stack_a, stack_b, lst_procedure);
	operate_pb(stack_a, stack_b, lst_procedure);
	ope_three_node(stack_a, stack_b, lst_procedure);
	return 1;
}
