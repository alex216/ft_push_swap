/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstdelone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:26:37 by yliu              #+#    #+#             */
/*   Updated: 2023/12/11 15:38:28 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void				ft_dl_lstdelone(t_dl_lst *lst_p, void (*del)(void *))
{
	if (lst_p == NULL || del == NULL)
		return ;
	(void)del;
	free(lst_p);
}
