/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:20:49 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 20:53:00 by yliu             ###   ########.fr       */
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
	else if (a_size >= 3 && a_size <= 5)
		ope_three_four_five_node(game_lists);
	else
		ope_long(game_lists);
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
	// TODO: Makefile norm violation to not use the wildcard TODO: not yet
	// TODO: checker pipe
	optimize_procedure(&game_lists.lst_procedure);
	print_procedure(game_lists.lst_procedure);
	free_all_lists(&game_lists);
	return (0);
}
