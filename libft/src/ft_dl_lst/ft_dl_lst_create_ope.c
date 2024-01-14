/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lst_create_ope.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:04:09 by yliu              #+#    #+#             */
/*   Updated: 2024/01/14 16:09:27 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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

void	ft_dl_lstadd_back_with_lst(t_lst **lst_pp, t_lst *new_p)
{
	t_lst	*sentinel_p;

	if(!new_p)
		return ;
	if (!lst_pp || !*lst_pp)
	{
		*lst_pp = ft_dl_lstadd_sentinel_to_node(new_p);
		if (!*lst_pp)
			return ;
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
}

void	ft_dl_lstadd_front_with_lst(t_lst **lst_pp, t_lst *new_p)
{
	if (!new_p)
		return ;
	if (!lst_pp || !*lst_pp)
	{
		*lst_pp = ft_dl_lstadd_sentinel_to_node(new_p);
		if (!*lst_pp)
			return ;
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
}

ssize_t	ft_dl_lstnew(t_lst **lst_pp, t_record *record_p)
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
		ft_dl_lstadd_back_with_lst(lst_pp, lst_p);
	return (true);
}
