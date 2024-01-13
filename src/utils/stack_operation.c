/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:26:49 by yliu              #+#    #+#             */
/*   Updated: 2024/01/13 14:30:15 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operate_sa(t_lst **lst_pp, t_lst **lst_procedure)
{
	operate_swap(lst_pp);
	put_to_procedure(lst_procedure, "sa");
}

void	operate_ra(t_lst **lst_a, t_lst **lst_procedure)
{
	operate_rotate(lst_a);
	put_to_procedure(lst_procedure, "ra");
}

void	operate_rra(t_lst **lst_a, t_lst **lst_procedure)
{
	operate_rev_rotate(lst_a);
	put_to_procedure(lst_procedure, "rra");
}
