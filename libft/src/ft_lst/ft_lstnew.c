/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:57:56 by yliu              #+#    #+#             */
/*   Updated: 2023/10/11 20:49:30 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst_p;

	lst_p = (t_list *)malloc(sizeof(t_list));
	if (lst_p == NULL)
		return (NULL);
	lst_p->content = content;
	lst_p->next = NULL;
	return (lst_p);
}
