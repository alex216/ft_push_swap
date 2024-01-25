/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:50:00 by yliu              #+#    #+#             */
/*   Updated: 2024/01/25 11:01:59 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stddef.h>

int	get_int_value_of(const t_lst *pointer);
char	*get_char_of(const t_lst *pointer);
void	*get_pointer_to_print(const t_lst *lst_p);
void	del_push_swap(void *lst_p);
void	*create_record(const char *str);

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

void	del_push_swap(void *lst_p)
{
	if (!lst_p)
		return ;
	free(((t_lst *)lst_p)->payload_p->char_content);
	free(((t_lst *)lst_p)->payload_p);
}

void	*create_record(const char *str)
{
	t_record	*payload_p;

	if (!str)
		return (NULL);
	payload_p = ft_calloc(1, sizeof(t_record));
	if (!payload_p)
		return (NULL);
	payload_p->char_content = ft_strdup(str);
	payload_p->int_data = ft_atoi(str);
	return (payload_p);
}
