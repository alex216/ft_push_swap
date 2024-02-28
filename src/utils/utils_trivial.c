/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_trivial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:33:20 by yliu              #+#    #+#             */
/*   Updated: 2024/02/26 20:20:16 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_game_list(t_game_lists *game)
{
	game->stack_a = NULL;
	game->stack_b = NULL;
	game->lst_procedure = NULL;
}

int	handle_abnormal_input(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	return (255);
}

void	print_procedure(const t_lst *i_p)
{
	if (!i_p)
		return ;
	while (!i_p->is_sentinel)
	{
		ft_printf("%s\n", get_char_of(i_p));
		i_p = i_p->next_p;
	}
}

void	free_all_lists(t_game_lists *game_lists)
{
	ft_dl_lstclear(&game_lists->stack_a, *del_push_swap);
	ft_dl_lstclear(&game_lists->stack_b, *del_push_swap);
	ft_dl_lstclear(&game_lists->lst_procedure, *del_push_swap);
}
