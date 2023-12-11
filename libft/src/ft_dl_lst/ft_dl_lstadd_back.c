/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:55:06 by yliu              #+#    #+#             */
/*   Updated: 2023/12/11 17:45:36 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "../../inc/ft_printf.h"

void	ft_dl_lstadd_back(t_dl_lst **lst_pp, t_dl_lst *new_p)
{
	t_dl_lst	*sentinel_p;

	if (lst_pp == NULL || new_p == NULL)
		return ;
	sentinel_p = (*lst_pp)->prev_p;
	new_p->prev_p = sentinel_p->prev_p;
	new_p->next_p = sentinel_p;
	sentinel_p->is_sentinel++;
	sentinel_p->prev_p->next_p = new_p;
	sentinel_p->prev_p = new_p;
}

// //////////////////////////////////////////
// static void	*del(void *tmp)
// {
// 	free(tmp);
// 	return (NULL);
// }
//
// int	main(void)
// {
// 	t_dl_lst	*origin_p;
// 	t_dl_lst	*tmp_p;
// 	t_dl_lst	*tmp1_p;
// 	t_dl_lst	*tmp2_p;
//
// 	origin_p = ft_dl_lstnew(16);
// 	tmp_p = ft_dl_lstcreate(32, 0);
// 	tmp1_p = ft_dl_lstcreate(64, 0);
// 	tmp2_p = ft_dl_lstcreate(8, 0);
// 	ft_dl_pf_lst(origin_p);
// 	ft_dl_lstadd_back(&origin_p, tmp_p);
// 	ft_dl_pf_lst(origin_p);
// 	ft_dl_lstadd_back(&origin_p, tmp1_p);
// 	ft_dl_pf_lst(origin_p);
// 	ft_dl_lstadd_front(&origin_p, tmp2_p);
// 	ft_dl_pf_lst(origin_p);
//
// 	ft_dl_lstclear(&origin_p, (void *)del);
//
// 	return (0);
// }
