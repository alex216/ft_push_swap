/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack_operation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:38:48 by yliu              #+#    #+#             */
/*   Updated: 2024/01/13 16:53:15 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	exchange_next_node_and_cur_node(t_lst *first_p)
{
	t_lst *second_p;

	second_p = first_p->next_p;
	first_p->prev_p->next_p = second_p;
	second_p->next_p->prev_p = first_p;
	second_p->prev_p = first_p->prev_p;
	first_p->prev_p = second_p;
	first_p->next_p = second_p->next_p;
	second_p->next_p = first_p;
}

void operate_swap_top_and_second_top(t_lst **lst_pp)
{
	t_lst	*tmp_p;

	tmp_p = *lst_pp;
	exchange_next_node_and_cur_node(tmp_p);
	*lst_pp = tmp_p->prev_p;
}

void operate_rotate_top_and_tail(t_lst **lst_pp)
{
	t_lst	*tmp_p;

	tmp_p = (*lst_pp)->prev_p;
	exchange_next_node_and_cur_node(tmp_p);
	*lst_pp = tmp_p->next_p;
}

void operate_rev_rotate_top_and_tail(t_lst **lst_pp)
{
	t_lst	*tmp_p;

	tmp_p = (*lst_pp)->prev_p->prev_p;
	exchange_next_node_and_cur_node(tmp_p);
	*lst_pp = tmp_p;
}
