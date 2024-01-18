/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_create_ope.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:04:09 by yliu              #+#    #+#             */
/*   Updated: 2024/01/18 13:22:59 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_lst *ft_dl_lstadd_sentinel_to_node(t_lst *lst_p);
bool	ft_dl_lstadd_back_with_lst(t_lst **lst_pp, t_lst *new_p);
bool	ft_dl_lstadd_front_with_lst(t_lst **lst_pp, t_lst *new_p);
bool	ft_dl_lstappend(t_lst **lst_pp, t_record *record_p);
t_lst	**ft_dl_lstdup(t_lst **lst_pp);

static t_lst *ft_dl_lstadd_sentinel_to_node(t_lst *lst_p)
{
	t_lst	*sentinel_p;

	sentinel_p = ft_dl_lstcreate_a_node(NULL, true);
	if (!sentinel_p)
		return (NULL);
	lst_p->next_p = sentinel_p;
	lst_p->prev_p = sentinel_p;
	sentinel_p->next_p = lst_p;
	sentinel_p->prev_p = lst_p;
	return (lst_p);
}

bool	ft_dl_lstadd_back_with_lst(t_lst **lst_pp, t_lst *new_p)
{
	t_lst	*sentinel_p;

	if(!new_p)
		return (false);
	if (!lst_pp || !*lst_pp)
	{
		*lst_pp = ft_dl_lstadd_sentinel_to_node(new_p);
		if (!*lst_pp)
			return (false);
	}
	else
	{
		sentinel_p = (*lst_pp)->prev_p;
		new_p->prev_p = sentinel_p->prev_p;
		new_p->next_p = sentinel_p;
		sentinel_p->is_sentinel++;
		sentinel_p->prev_p->next_p = new_p;
		sentinel_p->prev_p = new_p;
	}
	return (true);
}

bool	ft_dl_lstadd_front_with_lst(t_lst **lst_pp, t_lst *new_p)
{
	if (!new_p)
		return (false);
	if (!lst_pp || !*lst_pp)
	{
		*lst_pp = ft_dl_lstadd_sentinel_to_node(new_p);
		if (!*lst_pp)
			return (false);
	}
	else
	{
		new_p->prev_p = (*lst_pp)->prev_p;
		new_p->next_p = *lst_pp;
		(*lst_pp)->prev_p->is_sentinel++;
		(*lst_pp)->prev_p->next_p = new_p;
		(*lst_pp)->prev_p = new_p;
		*lst_pp = new_p;
	}
	return (true);
}

bool	ft_dl_lstappend(t_lst **lst_pp, t_record *record_p)
{
	t_lst		*lst_p;

	if (!record_p)
		return (false);
	lst_p = ft_dl_lstcreate_a_node(record_p, false);
	if (!lst_p)
		return (false);
	if (!lst_pp || !*lst_pp)
	{
		*lst_pp = ft_dl_lstadd_sentinel_to_node(lst_p);
		if (!*lst_pp)
			return (false);
	}
	else
	{
		if (!ft_dl_lstadd_back_with_lst(lst_pp, lst_p))
			return (false);
	}
	return (true);
}

// exit becase ans_pp is created inside this func.
t_lst	**ft_dl_lstdup(t_lst **lst_pp)
{
	t_lst	*iter_p;
	t_lst	**ans_pp;

	ans_pp = NULL;
	if (!lst_pp || !*lst_pp)
		return (NULL);
	iter_p = *lst_pp;
	while (!iter_p->is_sentinel)
	{
		if (!ft_dl_lstadd_back_with_lst(ans_pp, iter_p))
			exit(EXIT_FAILURE);
		iter_p = iter_p->next_p;
	}
	return (ans_pp);
}
