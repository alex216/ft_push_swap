/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_temp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:06:29 by yliu              #+#    #+#             */
/*   Updated: 2024/01/31 17:30:54 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

// empty array that satisfy all condtion concerning elements return false here
// dispite the math rule
bool	is_ascending_order(const t_lst *iter_p)
{
	int	cur;
	int	next;

	if (!iter_p)
		return (false);
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

bool	check_last_operation_is(const char *str, const t_lst **lst)
{
	char	*last_cmd;

	last_cmd = get_char_of(ft_dl_lstlast(*lst));
	return (!ft_strncmp(last_cmd, str, ft_strlen(str)));
}

size_t	return_number_to_rotate_ascending(t_lst **lst_pp, const t_lst *node_p)
{
	int		a_curr;
	int		a_prev;
	int		b_top;
	size_t	ra_counter;
	t_lst	*iter_p;

	if (!*lst_pp || ft_dl_lstsize(*lst_pp) == 1)
		return (0);
	ra_counter = 0;
	iter_p = *lst_pp;
	b_top = get_index_of(node_p);
	while (iter_p->is_sentinel == false)
	{
		a_curr = get_index_of(iter_p);
		if (iter_p->prev_p->is_sentinel)
			a_prev = get_index_of(iter_p->prev_p->prev_p);
		else
			a_prev = get_index_of(iter_p->prev_p);
		if ((a_prev < a_curr && (b_top > a_prev && b_top < a_curr))
			|| (a_prev > a_curr && (b_top > a_prev || b_top < a_curr)))
			break ;
		iter_p = iter_p->next_p;
		ra_counter++;
	}
	return (ra_counter);
}

size_t	return_number_to_rotate_descending(t_lst **lst_pp, const t_lst *node_p)
{
	int		a_curr;
	int		a_prev;
	int		b_top;
	size_t	ra_counter;
	t_lst	*iter_p;

	if (!*lst_pp || ft_dl_lstsize(*lst_pp) == 1)
		return (0);
	ra_counter = 0;
	iter_p = *lst_pp;
	b_top = get_index_of(node_p);
	while (iter_p->is_sentinel == false)
	{
		a_curr = get_index_of(iter_p);
		if (iter_p->prev_p->is_sentinel)
			a_prev = get_index_of(iter_p->prev_p->prev_p);
		else
			a_prev = get_index_of(iter_p->prev_p);
		if ((a_prev > a_curr && (b_top > a_prev && b_top < a_curr))
			|| (a_prev < a_curr && (b_top > a_prev || b_top < a_curr)))
			break ;
		iter_p = iter_p->next_p;
		ra_counter++;
	}
	return (ra_counter);
}
