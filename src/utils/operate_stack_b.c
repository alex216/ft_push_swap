/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:30:21 by yliu              #+#    #+#             */
/*   Updated: 2024/01/13 23:15:36 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	operate_sb(t_lst **stack_b, t_lst **lst_procedure)
{
	operate_swap_top_and_second_top(stack_b);
	append_to_procedure(lst_procedure, "sb");
}

void	operate_rb(t_lst **stack_b, t_lst **lst_procedure)
{
	operate_rotate_top_and_tail(stack_b);
	append_to_procedure(lst_procedure, "rb");
}

void	operate_rrb(t_lst **stack_b, t_lst **lst_procedure)
{
	operate_rev_rotate_top_and_tail(stack_b);
	append_to_procedure(lst_procedure, "rrb");
}

void	push_top_to_another_stack(t_lst **src_pp, t_lst **dst_pp)
{
	t_lst	*src_top_p;
	t_lst	*dst_top_p;

	src_top_p = *src_pp;
	dst_top_p = *dst_pp;
	src_top_p->next_p->prev_p = src_top_p->prev_p;
	src_top_p->prev_p->next_p = src_top_p->next_p;
	src_top_p->next_p = dst_top_p->next_p;
	src_top_p->prev_p = dst_top_p->prev_p;
	dst_top_p->next_p->prev_p = src_top_p;
	dst_top_p->prev_p->next_p = src_top_p;
	*src_pp = (*src_pp)->next_p;
	*dst_pp = src_top_p;
	(*src_pp)->prev_p->is_sentinel--;
	(*dst_pp)->prev_p->is_sentinel++;
}

void	operate_pb(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	push_top_to_another_stack(stack_a, stack_b);
	append_to_procedure(lst_procedure, "pb");
}
