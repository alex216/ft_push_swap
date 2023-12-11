/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstadd_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:15:19 by yliu              #+#    #+#             */
/*   Updated: 2023/12/11 17:59:42 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"
#include "../../inc/libft.h"

void	ft_dl_lstadd_front(t_dl_lst **lst_pp, t_dl_lst *new_p)
{
	if (lst_pp == NULL || *lst_pp == NULL || new_p == NULL)
		return ;
	new_p->prev_p = (*lst_pp)->prev_p;
	new_p->next_p = *lst_pp;
	(*lst_pp)->prev_p->is_sentinel++;
	(*lst_pp)->prev_p->next_p = new_p;
	(*lst_pp)->prev_p = new_p;
	*lst_pp = new_p;
}

// //////////////////////////////////////////
// int	main(void)
// {
// 	t_dl_lst	*origin_p;
// 	t_dl_lst	*tmp_p;
// 	t_dl_lst	*tmp1_p;
//
// 	origin_p = ft_dl_lstnew(42);
// 	tmp_p = ft_dl_lstcreate(2, false);
// 	tmp1_p = ft_dl_lstcreate(4, false);
// 	ft_dl_pf_lst(origin_p);
// 	ft_dl_lstadd_front(&origin_p, tmp_p);
// 	ft_dl_pf_lst(origin_p);
// 	ft_dl_lstadd_front(&origin_p, tmp1_p);
// 	ft_dl_pf_lst(origin_p);
// 	// must be freed by some func
// 	return (0);
// }
