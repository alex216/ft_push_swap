/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_temp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:06:29 by yliu              #+#    #+#             */
/*   Updated: 2024/01/15 10:12:50 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	append_to_procedure(t_lst **lst_procedure, char *string);
void	free_then_exit(void **double_pointer);
ssize_t	is_ascending_order(t_lst *iter_p);
void	a();

int	append_to_procedure(t_lst **lst_procedure, char *string)
{
	t_record	*record_p;

	record_p = create_record(string);
	return (ft_dl_lstnew(lst_procedure, record_p));
}

void	free_then_exit(void **double_pointer)
{
	ft_dl_lstclear((t_lst **)double_pointer, *del);
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

void	a()
{
	static void *operations_array[13];

	operations_array[0] = operate_sa;
	operations_array[1] = operate_sb;
	operations_array[2] = operate_ss;
	operations_array[3] = operate_pa;
	operations_array[4] = operate_pb;
	operations_array[5] = operate_ra;
	operations_array[6] = operate_rb;
	operations_array[7] = operate_rr;
	operations_array[8] = operate_rra;
	operations_array[9] = operate_rrb;
	operations_array[10] = operate_rrr;
};
