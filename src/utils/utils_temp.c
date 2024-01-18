/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_temp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:06:29 by yliu              #+#    #+#             */
/*   Updated: 2024/01/15 19:46:23 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	append_to_procedure(t_lst **lst_procedure, char *string);
void	free_then_exit(void **double_pointer);
ssize_t	is_ascending_order(t_lst *iter_p);
void	free_all(t_lst **lst_a, t_lst **lst_b, t_lst **lst_procedure);

void	append_to_procedure(t_lst **lst_procedure, char *string)
{
	t_record	*record_p;

	record_p = create_record(string);
	if (!record_p)
		exit(EXIT_FAILURE);
	if (!ft_dl_lstappend(lst_procedure, record_p))
		exit(EXIT_FAILURE);
}

void	free_then_exit(void **double_pointer)
{
	ft_dl_lstclear((t_lst **)double_pointer, *del_push_swap);
	exit(EXIT_FAILURE);
}

ssize_t	is_ascending_order(t_lst *iter_p)
{
	int	cur;
	int	next;

	while (!iter_p->next_p->is_sentinel)
	{
		cur = get_int_value_of(iter_p);
		next = get_int_value_of(iter_p->next_p);
		if (cur > next)
			return (false);
		iter_p = iter_p->next_p;
	}
	return (true);
}

void	free_all(t_lst **lst_a, t_lst **lst_b, t_lst **lst_procedure)
{
	ft_dl_lstclear(lst_a, *del_push_swap);
	ft_dl_lstclear(lst_b, *del_push_swap);
	ft_dl_lstclear(lst_procedure, *del_push_swap);
}
