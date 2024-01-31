/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_four_five_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:19:28 by yliu              #+#    #+#             */
/*   Updated: 2024/01/31 16:50:06 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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

void	sort_stack_using_only_ra_or_rra_in_fastest_way_in_a(t_lst **lst_pp, t_lst **lst_procedure)
{
	size_t	top_idx;
	size_t	lst_size;

	top_idx = get_index_of(*lst_pp) - 1;
	lst_size = ft_dl_lstsize(*lst_pp);
	if (2 * top_idx < lst_size)
		while (top_idx--)
			operate_rra(lst_pp, lst_pp, lst_procedure);
	else
		while (lst_size - top_idx++)
			operate_ra(lst_pp, lst_pp, lst_procedure);
}

void	sort_stack_using_only_ra_or_rra_in_fastest_way_in_b(t_lst **lst_pp, t_lst **lst_procedure)
{
	size_t	top_idx;
	size_t	lst_size;

	top_idx = get_index_of(*lst_pp) - 1;
	lst_size = ft_dl_lstsize(*lst_pp);
	if (2 * top_idx < lst_size)
		while (top_idx--)
			operate_rrb(lst_pp, lst_pp, lst_procedure);
	else
		while (lst_size - top_idx++)
			operate_rb(lst_pp, lst_pp, lst_procedure);
}

void	ope_four_five_node(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	size_t ra_counter;

	while (ft_dl_lstsize(*stack_a) > 3)
		operate_pb(stack_a, stack_b, lst_procedure);
	append_sa_if_needed(stack_a, stack_b, lst_procedure);
	while (*stack_b)
	{
		ra_counter = return_number_to_rotate_ascending(stack_a, *stack_b);
		_rotate_stack_in_shortest_way(stack_a, lst_procedure, ra_counter);
		operate_pa(stack_a, stack_b, lst_procedure);
	}
	sort_stack_using_only_ra_or_rra_in_fastest_way_in_a(stack_a, lst_procedure);
}
