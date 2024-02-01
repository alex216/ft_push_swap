/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct_get_context.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:50:00 by yliu              #+#    #+#             */
/*   Updated: 2024/01/31 17:29:27 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_index_of(const t_lst *lst_p)
{
	if (!lst_p)
		return (errno = EINVAL, 0);
	return (lst_p->payload_p->index);
}

int	get_int_value_of(const t_lst *lst_p)
{
	if (!lst_p)
		return (errno = EINVAL, 0);
	return (lst_p->payload_p->int_data);
}

char	*get_char_of(const t_lst *lst_p)
{
	if (!lst_p)
		return (NULL);
	return (lst_p->payload_p->char_content);
}

void	*get_pointer_to_print(const t_lst *lst_p)
{
	if (!lst_p)
		return (NULL);
	return (lst_p->payload_p->char_content);
}
