/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:03:07 by yliu              #+#    #+#             */
/*   Updated: 2023/09/28 19:24:36 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst_p, void (*f)(void *))
{
	if (lst_p == NULL || f == NULL)
		return ;
	while (lst_p != NULL)
	{
		f(lst_p->content);
		lst_p = lst_p->next;
	}
}
