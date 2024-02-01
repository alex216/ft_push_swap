/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:20:49 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 14:47:15 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_calculate_task(t_game_lists *game_lists)
{
	if (ft_dl_lstsize(game_lists->stack_a) == 1)
		return ;
	else if (ft_dl_lstsize(game_lists->stack_a) == 2)
		ope_two_node(game_lists);
	else if (ft_dl_lstsize(game_lists->stack_a) == 3)
		// ope_three_node(game_lists);
		ope_three_four_five_node(game_lists);
	else if (ft_dl_lstsize(game_lists->stack_a) == 4 || ft_dl_lstsize(game_lists->stack_a) == 5)
		ope_three_four_five_node(game_lists);
	else
		ope_long(game_lists);
	return ;
}

static void	_print_list(const t_lst *i_p)
{
	if (!i_p)
		return;
	while (!i_p->is_sentinel)
	{
		ft_printf("%s\n", get_char_of(i_p));
		i_p = i_p->next_p;
	}
}

// static void	_debug_stack(const t_lst **stack_a, const t_lst **stack_b)
// {
// 	(void) stack_a;
// 	(void) stack_b;
// 	#ifdef DEBUG
// 	ft_printf("a \n");
// 	ft_dl_pf_lst(*stack_a, get_pointer_to_print);
// 	ft_printf("b \n");
// 	ft_dl_pf_lst(*stack_b, get_pointer_to_print);
// 	ft_printf("\n");
// 	#endif
// }

int	main(int argc, char **argv)
{
	t_game_lists	game_lists;
	// TODO: Makefile norm violation to not use the wildcard

	game_lists.stack_a = NULL;
	game_lists.stack_b = NULL;
	game_lists.lst_procedure = NULL;
	argv_to_lst(argc, argv, &game_lists.stack_a);
	_calculate_task(&game_lists);
	// optimize_procedure(&lst_procedure);
	_print_list(game_lists.lst_procedure);
	free_all(&game_lists);
	return (0);
}
