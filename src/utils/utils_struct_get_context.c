/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct_get_context.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:50:00 by yliu              #+#    #+#             */
/*   Updated: 2024/02/08 16:35:52 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_index_of(const t_lst *lst_p)
{
	if (!lst_p)
		return (errno = EINVAL, 0);
	return (lst_p->payload_p->index);
}

int	get_int_value_of(const t_lst *lst_p)
{
	if (!lst_p)
		return (errno = EINVAL, 0);
	return (lst_p->payload_p->int_data);
}

char	*get_char_of(const t_lst *lst_p)
{
	if (!lst_p)
		return (NULL);
	return (lst_p->payload_p->char_content);
}

size_t	get_rotate_cost(t_lst **lst_pp, const t_lst *lst_p)
{
	int		cost;
	t_lst	*iter_p;

	if (!*lst_pp || !lst_p)
		return (errno = EINVAL, 0);
	cost = 0;
	iter_p = *lst_pp;
	while (iter_p->is_sentinel == false)
	{
		if (iter_p == lst_p)
			return (cost);
		cost++;
		iter_p = iter_p->next_p;
	}
	return (errno = EINVAL, 0);
}

size_t	get_min_cost_to_push(t_lst **lst_pp, const t_lst *iter_p)
{
	size_t	cost;
	size_t	cost_rev;

	if (!*lst_pp || !iter_p)
		return (errno = EINVAL, -1);
	cost = get_rotate_cost(lst_pp, iter_p);
	cost_rev = ft_dl_lstsize(*lst_pp) - cost;
	if (cost < cost_rev)
		return (cost);
	else
		return (cost_rev);
}
