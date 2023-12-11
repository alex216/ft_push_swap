/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:40:34 by yliu              #+#    #+#             */
/*   Updated: 2023/12/11 16:37:42 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void				ft_dl_lstclear(t_dl_lst **lst_pp, void (*del)(void *))
{
	t_dl_lst	*iter_p;
	t_dl_lst	*tmp_p;

	if (lst_pp == NULL || del == NULL)
		return ;
	if (*lst_pp == NULL)
		return ;
	iter_p = *lst_pp;
	while (iter_p->is_sentinel == 0)
	{
		tmp_p = iter_p->next_p;
		ft_dl_lstdelone(iter_p, del);
		iter_p = tmp_p;
	}
	ft_dl_lstdelone(iter_p,del);
	*lst_pp = NULL;
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
//
// 	origin_p = ft_dl_lstnew(42);
// 	tmp_p = ft_dl_lstcreate(2, false);
// 	tmp1_p = ft_dl_lstcreate(4, false);
// 	ft_dl_pf_lst(origin_p);
// 	ft_dl_lstadd_front(&origin_p, tmp_p);
// 	ft_dl_pf_lst(origin_p);
// 	ft_dl_lstadd_front(&origin_p, tmp1_p);
// 	ft_dl_pf_lst(origin_p);
//
// 	ft_dl_lstclear(&origin_p, (void *)del);
//
// 	return (0);
// }
