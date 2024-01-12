/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_three_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:39:43 by yliu              #+#    #+#             */
/*   Updated: 2024/01/12 15:36:25 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	put_to_procedure(t_lst **lst_procedure, char *string)
{
	t_record	*record_p;

	record_p = create_record(string);
	return (create_new_dl_lst(lst_procedure, record_p));
}

ssize_t	ope_three_node(t_lst **lst_a, t_lst **lst_b, t_lst **lst_procedure)
{
	(void)lst_procedure;
	(void)lst_b;

	if (get_int_value_of(*lst_a) > get_int_value_of((*lst_a)->next_p))
		if (get_int_value_of((*lst_a)) < get_int_value_of((*lst_a)->next_p->next_p))
			if (get_int_value_of((*lst_a)->next_p) < get_int_value_of((*lst_a)->next_p->next_p))
				put_to_procedure(lst_procedure, "sa");
	return (1);
}
