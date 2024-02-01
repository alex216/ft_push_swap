/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_basic_stack_ope2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:21:49 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 14:24:57 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lst	*_pick_top_from_stack(t_lst **lst_pp)
{
	t_lst	*top_p;

	top_p = *lst_pp;
	if (top_p->next_p->is_sentinel == 1)
	{
		free(top_p->next_p);
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

bool	operate_push_top_to_another_stack(t_lst **src_pp, t_lst **dst_pp)
{
	t_lst	*top_p;

	top_p = _pick_top_from_stack(src_pp);
	if (!top_p)
		return (false);
	return (ft_dl_lstadd_front_with_lst(dst_pp, top_p));
}
