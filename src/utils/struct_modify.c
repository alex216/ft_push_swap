/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_modify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:27:32 by yliu              #+#    #+#             */
/*   Updated: 2024/01/31 17:33:50 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	append_to_procedure(t_lst **lst_procedure, const char *string)
{
	t_record	*record_p;

	record_p = create_record(string);
	if (!record_p)
		exit(EXIT_FAILURE);
	if (!ft_dl_lstappend(lst_procedure, record_p))
		exit(EXIT_FAILURE);
}
