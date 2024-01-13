/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:50:00 by yliu              #+#    #+#             */
/*   Updated: 2024/01/13 16:58:09 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_int_value_of(t_lst *pointer)
{
	return (pointer->payload_p->int_data);
}

char	*get_char_value_of(t_lst *pointer)
{
	return (pointer->payload_p->char_content);
}

void	pf_debug(void)
{
	ft_printf("!");
}

void	del(void *t_lst_p)
{
	free(((t_lst *)t_lst_p)->payload_p->char_content);
	free(((t_lst *)t_lst_p)->payload_p);
}

void	free_then_exit(void **double_pointer)
{
	ft_dl_lstclear((t_lst **)double_pointer, *del);
	exit(EXIT_FAILURE);
}

void	*create_record(char *str)
{
	t_record	*payload_p;

	if (str == NULL)
		return (NULL);
	payload_p = ft_calloc(1, sizeof(t_record));
	if (payload_p == NULL)
		return (NULL);
	payload_p->char_content = ft_strdup(str);
	payload_p->int_data = ft_atoi(str);
	return (payload_p);
}

ssize_t	create_new_dl_lst(t_lst **lst_a, t_record *record_p)
{
	t_lst		*t_lst_p;

	if (!record_p)
		return (false);
	if (!lst_a || !*lst_a)
	{
		*lst_a = ft_dl_lstnew(record_p);
		if (!lst_a)
			return (false);
	}
	else
	{
		t_lst_p = ft_dl_lstcreate(record_p, false);
		if (!t_lst_p)
			return (false);
		ft_dl_lstadd_back(lst_a, t_lst_p);
	}
	return (true);
}

int	append_to_procedure(t_lst **lst_procedure, char *string)
{
	t_record	*record_p;

	record_p = create_record(string);
	return (create_new_dl_lst(lst_procedure, record_p));
}

