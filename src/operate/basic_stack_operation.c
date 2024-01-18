/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack_operation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:38:48 by yliu              #+#    #+#             */
/*   Updated: 2024/01/15 15:16:56 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	exchange_next_node_and_cur_node(t_lst *first_p);
void	operate_swap_top_and_second_top(t_lst **lst_pp);
void	operate_rotate_top_and_tail(t_lst **lst_pp);
void	operate_rev_rotate_top_and_tail(t_lst **lst_pp);
bool	push_top_to_another_stack(t_lst **src_pp, t_lst **dst_pp);

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

	if (ft_dl_lstsize(*lst_pp) == 1)
		return ;
	tmp_p = *lst_pp;
	exchange_next_node_and_cur_node(tmp_p);
	*lst_pp = tmp_p->prev_p;
}

void operate_rotate_top_and_tail(t_lst **lst_pp)
{
	t_lst	*tmp_p;

	if (ft_dl_lstsize(*lst_pp) == 1)
		return ;
	tmp_p = (*lst_pp)->prev_p;
	exchange_next_node_and_cur_node(tmp_p);
	*lst_pp = tmp_p->next_p;
}

void operate_rev_rotate_top_and_tail(t_lst **lst_pp)
{
	t_lst	*tmp_p;

	if (ft_dl_lstsize(*lst_pp) == 1)
		return ;
	tmp_p = (*lst_pp)->prev_p->prev_p;
	exchange_next_node_and_cur_node(tmp_p);
	*lst_pp = tmp_p;
}

static t_lst *pick_top_from_stack(t_lst **lst_pp)
{
	t_lst	*top_p;

	if (!lst_pp || !*lst_pp)
		return (NULL);
	top_p = *lst_pp;
	if (ft_dl_lstsize(*lst_pp) == 1)
	{
		free(top_p->prev_p);
		*lst_pp = NULL;
	}
	else
	{
		*lst_pp = top_p->next_p;
		top_p->prev_p->is_sentinel--;
		top_p->next_p->prev_p = top_p->prev_p;
		top_p->prev_p->next_p = top_p->next_p;
	}
	top_p->next_p = NULL;
	top_p->prev_p = NULL;
	return (top_p);
}

bool	push_top_to_another_stack(t_lst **src_pp, t_lst **dst_pp)
{
	t_lst *tmp_p;

	if (!src_pp || !*src_pp)
		return (false);
	tmp_p = (pick_top_from_stack(src_pp));
	if (!tmp_p)
		return (false);
	return (ft_dl_lstadd_front_with_lst(dst_pp, tmp_p));
}
