/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:02:51 by yliu              #+#    #+#             */
/*   Updated: 2023/09/30 01:20:20 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst_p, void (*del)(void *))
{
	if (lst_p == NULL || del == NULL)
		return ;
	del(lst_p->content);
	free(lst_p);
}
