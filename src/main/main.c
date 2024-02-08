/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:20:43 by yliu              #+#    #+#             */
/*   Updated: 2024/02/08 18:57:10 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_calculate_procedure(t_game_lists *game_lists)
{
	int	a_size;

	if (is_ascending_order(game_lists->stack_a))
		return ;
	a_size = ft_dl_lstsize(game_lists->stack_a);
	if (a_size == 2)
		operate_sa(game_lists);
	if (a_size >= 3 && a_size <= 5)
		ope_three_four_five_node(game_lists);
	else
		// ope_select_insert(game_lists);
		ope_quick_sort(game_lists);
	return ;
}

int	main(int argc, char **argv)
{
	t_game_lists	game_lists;

	game_lists.stack_a = NULL;
	game_lists.stack_b = NULL;
	game_lists.lst_procedure = NULL;
	copy_argv_to_lst(argc, argv, &game_lists.stack_a);
	_calculate_procedure(&game_lists);
	// TODO: Makefile norm violation to not use the wildcard
	// TODO: last three node is really expensive
	// TODO: adjust cost func to choose opposite position of exit of stack_a
	optimize_procedure(&game_lists.lst_procedure);
	#ifndef DEBUG2
	print_procedure(game_lists.lst_procedure);
	#endif
	// debug_func(&game_lists);
	free_all_lists(&game_lists);
	return (0);
}
