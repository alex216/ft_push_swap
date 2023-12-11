/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstcreate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:27:43 by yliu              #+#    #+#             */
/*   Updated: 2023/12/11 14:28:09 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_dl_lst	*ft_dl_lstcreate(int content, bool is_sentinel)
{
	t_dl_lst	*lst_p;

	lst_p = ft_calloc(1, sizeof(t_dl_lst));
	if (lst_p == NULL)
		return (NULL);
	lst_p->int_data = content;
	lst_p->is_sentinel = is_sentinel;
	lst_p->next_p = NULL;
	lst_p->prev_p = NULL;
	return (lst_p);
}
