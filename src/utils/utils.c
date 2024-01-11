/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:50:00 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 15:56:02 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void *t_lst_p)
{
	free(((t_lst *)t_lst_p)->payload_p->char_content);
	free(((t_lst *)t_lst_p)->payload_p);
}

void	free_then_exit(void **double_pointer)
{
	ft_dl_lstclear((t_lst **)double_pointer, *del);
	exit(1);
}

void	*create(char *str)
{
	t_record	*payload_p;

	if (str == NULL)
		return (NULL);
	payload_p = ft_calloc(1, sizeof(t_record));
	if (payload_p == NULL)
		return (NULL);
	payload_p->char_content = ft_strdup(str);
	return (payload_p);
}

void	pf_debug(void)
{
	ft_printf("!");
}
