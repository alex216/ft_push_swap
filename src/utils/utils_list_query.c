/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_query.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:44:23 by yliu              #+#    #+#             */
/*   Updated: 2024/02/06 12:40:30 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	_is_index_among_ascending(t_lst *prev_p, t_lst *curr_p, int x)
{
	int	curr;
	int	prev;

	curr = get_index_of(curr_p);
	prev = get_index_of(prev_p);
	if (prev < curr)
		if (x > prev && x < curr)
			return (true);
	if (prev > curr)
		if (x > prev || x < curr)
			return (true);
	return (false);
}

static bool	_is_index_among_descending(t_lst *prev_p, t_lst *curr_p, int x)
{
	int	curr;
	int	prev;

	curr = get_index_of(curr_p);
	prev = get_index_of(prev_p);
	if (prev > curr)
		if (x < prev && x > curr)
			return (true);
	if (prev < curr)
		if (x < prev || x > curr)
			return (true);
	return (false);
}

size_t	return_num_to_ascending(t_lst **lst_pp, const t_lst *node_p)
{
	int		top;
	size_t	ra_counter;
	t_lst	*iter_p;

	if (!*lst_pp || ft_dl_lstsize(*lst_pp) == 1)
		return (0);
	iter_p = *lst_pp;
	top = get_index_of(node_p);
	if (_is_index_among_ascending(iter_p->prev_p->prev_p, iter_p, top))
		return (0);
	iter_p = iter_p->next_p;
	ra_counter = 1;
	while (iter_p->is_sentinel == false)
	{
		if (_is_index_among_ascending(iter_p->prev_p, iter_p, top))
			break ;
		iter_p = iter_p->next_p;
		ra_counter++;
	}
	return (ra_counter);
}

size_t	return_num_to_descending(t_lst **lst_pp, const t_lst *node_p)
{
	int		top;
	size_t	ra_counter;
	t_lst	*iter_p;

	if (!*lst_pp || ft_dl_lstsize(*lst_pp) == 1)
		return (0);
	iter_p = *lst_pp;
	top = get_index_of(node_p);
	if (_is_index_among_descending(iter_p->prev_p->prev_p, iter_p, top))
		return (0);
	iter_p = iter_p->next_p;
	ra_counter = 1;
	while (iter_p->is_sentinel == false)
	{
		if (_is_index_among_descending(iter_p->prev_p, iter_p, top))
			break ;
		iter_p = iter_p->next_p;
		ra_counter++;
	}
	return (ra_counter);
}

// empty array returns true
bool	is_ascending_order(const t_lst *iter_p)
{
	int	cur;
	int	next;

	if (!iter_p)
		return (true);
	while (iter_p && !iter_p->next_p->is_sentinel)
	{
		cur = get_int_value_of(iter_p);
		next = get_int_value_of(iter_p->next_p);
		if (cur > next)
			return (false);
		iter_p = iter_p->next_p;
	}
	return (true);
}
