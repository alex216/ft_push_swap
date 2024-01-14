/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:50:00 by yliu              #+#    #+#             */
/*   Updated: 2024/01/14 15:51:15 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

	if (!str)
		return (NULL);
	payload_p = ft_calloc(1, sizeof(t_record));
	if (!payload_p)
		return (NULL);
	payload_p->char_content = ft_strdup(str);
	payload_p->int_data = ft_atoi(str);
	return (payload_p);
}


int	append_to_procedure(t_lst **lst_procedure, char *string)
{
	t_record	*record_p;

	record_p = create_record(string);
	return (ft_dl_lstnew(lst_procedure, record_p));
}

void	*get_pointer_to_print(t_lst *lst_p)
{
	return (lst_p->payload_p->char_content);
}
