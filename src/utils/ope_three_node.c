/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_three_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:39:43 by yliu              #+#    #+#             */
/*   Updated: 2024/01/31 17:33:24 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ope_three_node(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	append_sa_if_needed(stack_a, stack_b, lst_procedure);
	sort_stack_using_only_ra_or_rra_in_fastest_way_in_a(stack_a, lst_procedure);
}
