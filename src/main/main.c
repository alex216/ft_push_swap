/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:20:49 by yliu              #+#    #+#             */
/*   Updated: 2024/01/20 17:25:10 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

static void	_print_list(t_lst *i_p);
static void	_debug_stack(t_lst **stack_a, t_lst **stack_b);
int	main(int argc, char **argv);

static void	_calculate_task(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	// if (ft_dl_lstsize(*stack_a) == 2)
	// 	ope_two_node(stack_a, lst_procedure);
	// if (ft_dl_lstsize(*stack_a) == 3)
	// 	ope_three_node(stack_a, stack_b, lst_procedure);
	if (ft_dl_lstsize(*stack_a) == 3)
		ope_less_six_node(stack_a, stack_b, lst_procedure);
	// ope_long_node();
	return ;
}

static void	_print_list(t_lst *i_p)
{
	while(!i_p->is_sentinel)
	{
		ft_printf("%s\n", get_char_value_of(i_p));
		i_p = i_p->next_p;
	}
}

static void	_debug_stack(t_lst **stack_a, t_lst **stack_b)
{
	(void)stack_a;
	(void)stack_b;
	#ifdef DEBUG
	ft_printf("a \n");
	ft_dl_pf_lst(*stack_a, get_pointer_to_print);
	ft_printf("b \n");
	ft_dl_pf_lst(*stack_b, get_pointer_to_print);
	ft_printf("\n");
	#endif
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	t_lst	*lst_procedure;

	stack_a = NULL;
	stack_b = NULL;
	lst_procedure = NULL;
	argv_to_lst(argc, argv, &stack_a);
	_debug_stack(&stack_a, &stack_b);
	_calculate_task(&stack_a, &stack_b, &lst_procedure);
	// optimize_procedure(&lst_procedure);
	_debug_stack(&stack_a, &stack_b);
	_print_list(lst_procedure);
	free_all(&stack_a, &stack_b, &lst_procedure);
	return (0);
}
