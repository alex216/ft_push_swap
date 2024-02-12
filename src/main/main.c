/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:20:43 by yliu              #+#    #+#             */
/*   Updated: 2024/02/12 13:48:44 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_game_lists	game_lists;

	// TODO: makefile relink
	initialize_game_list(&game_lists);
	copy_argv_to_lst(argc, argv, &game_lists.stack_a);
	calculate_procedure(&game_lists);
	print_procedure(game_lists.lst_procedure);
	optimize_procedure(&game_lists.lst_procedure);
	free_all_lists(&game_lists);
	return (0);
}
