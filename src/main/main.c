/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:20:49 by yliu              #+#    #+#             */
/*   Updated: 2024/01/14 21:11:39 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

static void	_calculate_task(t_lst **lst_a, t_lst **lst_b, t_lst **lst_procedure);
static void	_free_all(t_lst **lst_a, t_lst **lst_b, t_lst **lst_procedure);
static void	_print_list(t_lst *i_p);
static void	_debug_stack(t_lst **stack_a, t_lst **stack_b);
int	main(int argc, char **argv);

static void	_calculate_task(t_lst **lst_a, t_lst **lst_b, t_lst **lst_procedure)
{
	if (ft_dl_lstsize(*lst_a) == 2)
		ope_two_node(lst_a, lst_procedure);
	if (ft_dl_lstsize(*lst_a) == 3)
		ope_three_node(lst_a, lst_procedure);
	if (ft_dl_lstsize(*lst_a) == 5)
		ope_five_node(lst_a, lst_b, lst_procedure);
	// ope_long_node();
	return ;
}

static void	_free_all(t_lst **lst_a, t_lst **lst_b, t_lst **lst_procedure)
{
	ft_dl_lstclear(lst_a, del);
	ft_dl_lstclear(lst_b, del);
	ft_dl_lstclear(lst_procedure, del);
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
	_free_all(&stack_a, &stack_b, &lst_procedure);
	return (0);
}
