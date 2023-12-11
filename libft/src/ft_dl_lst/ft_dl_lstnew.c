/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:04:09 by yliu              #+#    #+#             */
/*   Updated: 2023/12/11 13:02:06 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static t_dl_lst	*ft_dl_lstcreate(int content, bool is_sentinel)
{
	t_dl_lst	*lst_p;

	lst_p = ft_calloc(1, sizeof(t_dl_lst));
	if (lst_p == NULL)
		return (NULL);
	lst_p->int_data = content;
	lst_p->is_sentinel = is_sentinel;

	return (lst_p);
}

t_dl_lst	*ft_dl_lstnew(int content)
{
	t_dl_lst	*lst_p;
	t_dl_lst	*sentinel_p;

	lst_p = ft_dl_lstcreate(content, false);
	sentinel_p = ft_dl_lstcreate(0, true);
	if (lst_p == NULL || sentinel_p == NULL)
	{
		free(lst_p);
		free(sentinel_p);
		return (NULL);
	}
	lst_p->next_p = sentinel_p;
	lst_p->prev_p = sentinel_p;
	sentinel_p->next_p = lst_p;
	sentinel_p->prev_p = lst_p;
	return (lst_p);
}

// //////////////////////////////////////////
// #include <stdio.h>
// int	main(void)
// {
// 	t_dl_lst	*tmp;
// 	tmp = ft_dl_lstnew(-1);
// 	printf("%d\n", tmp->int_data);
// 	printf("%d\n", tmp->is_sentinel);
// 	printf("%d\n", tmp->next_p->int_data);
// 	printf("%d\n", tmp->next_p->is_sentinel);
// 	printf("%d\n", tmp->prev_p->int_data);
// 	printf("%d\n", tmp->prev_p->is_sentinel);
// 	free(tmp->next_p);
// 	free(tmp);
//
// 	return (0);
// }
