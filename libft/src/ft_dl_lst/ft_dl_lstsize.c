/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_lstsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:05:17 by yliu              #+#    #+#             */
/*   Updated: 2023/12/11 16:05:18 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_lstsize(t_list *lst_p)
{
	size_t	i;

	if (lst_p == NULL)
		return (0);
	i = 1;
	while (lst_p->next != NULL)
	{
		lst_p = lst_p->next;
		i++;
	}
	return ((int)i);
}
