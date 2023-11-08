/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:30:30 by yliu              #+#    #+#             */
/*   Updated: 2023/09/30 01:18:42 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst_pp, t_list *new_p)
{
	if (lst_pp == NULL || new_p == NULL)
		return ;
	new_p->next = *lst_pp;
	*lst_pp = new_p;
}
