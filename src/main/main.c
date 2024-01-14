/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:20:49 by yliu              #+#    #+#             */
/*   Updated: 2024/01/14 00:10:50 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

// TODO: "1 2" 3 4 "5"
// todo: duplicates, incorrectly formatted.
// todo: algorithm.

static void	calculate_task(t_lst **lst_a, t_lst **lst_b, t_lst **lst_procedure)
{
	if (ft_dl_lstsize(*lst_a) == 2)
		ope_two_node(lst_a, lst_procedure);
	if (ft_dl_lstsize(*lst_a) == 3)
		ope_three_node(lst_a, lst_b, lst_procedure);
	if (ft_dl_lstsize(*lst_a) == 5)
		ope_five_node(lst_a, lst_b, lst_procedure);
	// return (ope_long_node);
	return ;
}

static void	free_all(t_lst **lst_a, t_lst **lst_b, t_lst **lst_procedure)
{
	(void)lst_procedure;
	ft_dl_lstclear(lst_a, del);
	ft_dl_lstclear(lst_b, del);
	ft_dl_lstclear(lst_procedure, del);
}

static void	print_list(t_lst *i_p)
{
	while(!i_p->is_sentinel)
	{
		ft_printf("%s\n", get_char_value_of(i_p));
		i_p = i_p->next_p;
	}
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
	ft_dl_pf_lst(stack_a, get_pointer_to_print);
	ft_printf("\n");
	calculate_task(&stack_a, &stack_b, &lst_procedure);
	// // optimize_procedure(&lst_procedure);
	ft_dl_pf_lst(stack_a, get_pointer_to_print);
	ft_printf("\n");
	print_list(lst_procedure);
	free_all(&stack_a, &stack_b, &lst_procedure);
	return (0);
}
