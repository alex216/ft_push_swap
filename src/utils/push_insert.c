/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:16:41 by yliu              #+#    #+#             */
/*   Updated: 2024/01/31 17:10:28 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

static void _operate_ra_rb(int ra, int rb, t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	int	ra_rb_min;

	ra_rb_min = ft_min(ra, rb);
	while (ra-- > ra_rb_min)
		operate_ra(stack_a, stack_b, lst_procedure);
	while (rb-- > ra_rb_min)
		operate_rb(stack_a, stack_b, lst_procedure);
	while (ra_rb_min--)
		operate_rr(stack_a, stack_b, lst_procedure);
	operate_pb(stack_a, stack_b, lst_procedure);
}

// this can be ra then rrb or rrb then ra
static void _operate_ra_rrb(int ra, int rb, t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	int	rrb;

	rrb = ft_dl_lstsize(*stack_b) - rb;
	while (ra--)
		operate_ra(stack_a, stack_b, lst_procedure);
	ra++;
	while (rrb--)
		operate_rrb(stack_a, stack_b, lst_procedure);
	operate_pb(stack_a, stack_b, lst_procedure);
}

// this can be rra then rb or rb then rra
static void _operate_rra_rb(int ra, int rb, t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	int	rra;

	rra = ft_dl_lstsize(*stack_a) - ra;
	while (rra--)
		operate_rra(stack_a, stack_b, lst_procedure);
	rra++;
	while (rb--)
		operate_rb(stack_a, stack_b, lst_procedure);
	operate_pb(stack_a, stack_b, lst_procedure);
}

static void _operate_rra_rrb(int ra, int rb, t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	int rra;
	int	rrb;
	int	rra_rrb_min;

	rra = ft_dl_lstsize(*stack_a) - ra;
	rrb = ft_dl_lstsize(*stack_b) - rb;
	rra_rrb_min = ft_min(rra, rrb);
	while (rra-- > rra_rrb_min)
		operate_rra(stack_a, stack_b, lst_procedure);
	while (rrb-- > rra_rrb_min)
		operate_rrb(stack_a, stack_b, lst_procedure);
	while (rra_rrb_min--)
		operate_rrr(stack_a, stack_b, lst_procedure);
	operate_pb(stack_a, stack_b, lst_procedure);
}

void	execute_optimized_push(int minimum, int ra, t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	int		temp_index;
	int		rb;
	int		rra;
	int		rrb;
	t_lst	*iter_p;

	temp_index = ra;
	iter_p = *stack_a;
	while (temp_index--)
		iter_p = iter_p->next_p;
	rra = ft_dl_lstsize(*stack_a) - ra;
	// rb = return_number_to_rotate_descending(stack_b, iter_p);
	rb = return_number_to_rotate_ascending(stack_b, iter_p);
	rrb = ft_dl_lstsize(*stack_b) - rb;

	if (ft_max(ra, rb) == minimum)
		_operate_ra_rb(ra, rb, stack_a, stack_b, lst_procedure);
	else if (ra + rrb == minimum)
		_operate_ra_rrb(ra, rb, stack_a, stack_b, lst_procedure);
	else if (rra + rb == minimum)
		_operate_rra_rb(ra, rb, stack_a, stack_b, lst_procedure);
	if (ft_max(rra, rrb)== minimum)
		_operate_rra_rrb(ra, rb, stack_a, stack_b, lst_procedure);
}
