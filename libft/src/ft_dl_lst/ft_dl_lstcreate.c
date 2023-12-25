/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstcreate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:27:43 by yliu              #+#    #+#             */
/*   Updated: 2023/12/25 15:01:56 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// create one node from record
// NULL guard is not ignored, because this func needs to create sentinel node
t_lst	*ft_dl_lstcreate(t_record *record_p, size_t is_sentinel)
{
	t_lst	*lst_p;

	lst_p = ft_calloc(1, sizeof(t_lst));
	if (lst_p == NULL)
		return (NULL);
	lst_p->payload_p = record_p;
	lst_p->is_sentinel = is_sentinel;
	lst_p->next_p = NULL;
	lst_p->prev_p = NULL;
	return (lst_p);
}
