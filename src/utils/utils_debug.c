/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:23:01 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 17:20:45 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	debug_func(const t_lst **a, const t_lst **b, const t_lst **tmp)
{
	ft_dl_pf_lst(*a, get_pointer_to_print);
	ft_dl_pf_lst(*b, get_pointer_to_print);
	ft_dl_pf_lst(*tmp, get_pointer_to_print);
}

void	print_index(const t_lst **lst_pp)
{
	const t_lst	*iter_p;

	iter_p = *lst_pp;
	while (iter_p->is_sentinel == false)
	{
		ft_printf("elem [%d] idx [%d]\n", get_int_value_of(iter_p),
			get_index_of(iter_p));
		iter_p = iter_p->next_p;
	}
}