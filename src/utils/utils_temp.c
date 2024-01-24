/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_temp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:06:29 by yliu              #+#    #+#             */
/*   Updated: 2024/01/24 15:21:01 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_to_procedure(t_lst **lst_procedure, const char *string);
bool	is_ascending_order(const t_lst *iter_p);
void	free_all(t_lst **lst_a, t_lst **lst_b, t_lst **lst_procedure);
bool	check_last_operation_is(const char *str, const t_lst **lst);

void	append_to_procedure(t_lst **lst_procedure, const char *string)
{
	t_record	*record_p;

	record_p = create_record(string);
	if (!record_p)
		exit(EXIT_FAILURE);
	if (!ft_dl_lstappend(lst_procedure, record_p))
		exit(EXIT_FAILURE);
}

// empty array that satisfy all condtion concerning elements return false here
// dispite the math rule
bool	is_ascending_order(const t_lst *iter_p)
{
	int	cur;
	int	next;

	if (!iter_p)
		return (false);
	while (iter_p && !iter_p->next_p->is_sentinel)
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

bool	check_last_operation_is(const char *str, const t_lst **lst)
{
	char	*last_cmd;

	last_cmd = get_char_of(ft_dl_lstlast(*lst));
	return (!ft_strncmp(last_cmd, str, ft_strlen(str)));
}

int	g_count = 0;
void	debug_func(t_lst **a, t_lst **b, t_lst **tmp, char *q, char *w, char *e)
{
	g_count++;
	ft_printf("print is called [%d]\n", g_count);
	ft_printf("%s    ", q);
	ft_dl_pf_lst(*a, get_pointer_to_print);
	ft_printf("%s    ", w);
	ft_dl_pf_lst(*b, get_pointer_to_print);
	ft_printf("%s    ", e);
	ft_dl_pf_lst(*tmp, get_pointer_to_print);
}

ope_p	*define_function_pointer(void)
{
	static ope_p ope_array[OPERATION_NUMBER];

	ope_array[0] = operate_sa;
	ope_array[1] = operate_sb;
	ope_array[2] = operate_ss;
	ope_array[3] = operate_pa;
	ope_array[4] = operate_pb;
	ope_array[5] = operate_ra;
	ope_array[6] = operate_rb;
	ope_array[7] = operate_rr;
	ope_array[8] = operate_rra;
	ope_array[9] = operate_rrb;
	ope_array[10] = operate_rrr;
	return (ope_array);
}
