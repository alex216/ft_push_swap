/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_four_five_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:19:28 by yliu              #+#    #+#             */
/*   Updated: 2024/01/25 14:04:02 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static size_t _return_number_to_rotate(t_lst **lst_pp, const t_lst *node_p)
{
	int a_curr;
	int	a_prev;
	int	b_top;
	size_t	ra_counter;
	t_lst	*iter_p;

	if (!*lst_pp || ft_dl_lstsize(*lst_pp) == 1)
		return (0);
	ra_counter = 1;
	iter_p = (*lst_pp)->next_p;
	b_top = get_index_of(node_p);
	while (iter_p->is_sentinel == false)
	{
		a_curr = get_index_of(iter_p);
		a_prev = get_index_of(iter_p->prev_p);
		if (a_prev < b_top && b_top < a_curr)
			break;
		iter_p = iter_p->next_p;
		ra_counter++;
	}
	return (ra_counter);
}

static	bool	_rotate_stack_in_shortest_way(t_lst **lst_pp, t_lst ** lst_procedure, size_t ra_counter)
{
	size_t	lst_size;

	lst_size = ft_dl_lstsize(*lst_pp);
	if (2 * ra_counter < lst_size)
		while (ra_counter--)
			operate_ra(lst_pp, lst_pp, lst_procedure);
	else
		while (lst_size - ra_counter++)
			operate_rra(lst_pp, lst_pp, lst_procedure);
	return (true);
}

// static void	_sort_stack_using_only_ra_or_rra(t_lst **lst_pp, t_lst **lst_procedure)
// {
// 	size_t	top_idx;
// 	size_t	lst_size;
//
// 	top_idx = get_index_of(*lst_pp);
// 	lst_size = ft_dl_lstsize(*lst_pp);
// 	if (2 * top_idx < lst_size)
// 		while (top_idx--)
// 			operate_ra(lst_pp, lst_pp, lst_procedure);
// 	else
// 		while (lst_size - top_idx++)
// 			operate_rra(lst_pp, lst_pp, lst_procedure);
// }

void	ope_four_five_node(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	size_t ra_counter;

	while (ft_dl_lstsize(*stack_a) > 3)
		operate_pb(stack_a, stack_b, lst_procedure);
	ope_three_node(stack_a, stack_b, lst_procedure);

	while (*stack_b)
	{
		ra_counter = _return_number_to_rotate(stack_a, *stack_b);
		ft_printf("ra counter %d\n", ra_counter);
		_rotate_stack_in_shortest_way(stack_a, lst_procedure, ra_counter);
		operate_pa(stack_a, stack_b, lst_procedure);
		debug_func(stack_a, stack_b, lst_procedure, "a\t", "b\t", "lst\t");
	}
	// debug_func(stack_a, stack_b, lst_procedure, "a\t", "b\t", "lst\t");
	// _sort_stack_using_only_ra_or_rra(stack_a, lst_procedure);
	// debug_func(stack_a, stack_b, lst_procedure, "a\t", "b\t", "lst\t");
}
