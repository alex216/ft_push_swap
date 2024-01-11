/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:04:09 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 11:54:31 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// create dl_lst from record
t_lst	*ft_dl_lstnew(t_record *record_p)
{
	t_lst	*lst_p;
	t_lst	*sentinel_p;

	if (record_p == NULL)
		return (NULL);
	lst_p = ft_dl_lstcreate(record_p, 0);
	sentinel_p = ft_dl_lstcreate(NULL, 1);
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
// 	t_lst	*tmp;
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
