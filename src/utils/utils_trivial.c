/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_trivial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:33:20 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 17:51:46 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_abnormal_input(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	return (255);
}

// sa -> sa
// ra -> rra
// rra -> ra
// pa -> pb
// pb -> pa
// sb -> sb
// rb -> rrb
// rrb -> rb
// ss -> ss
// rr -> rrr
// rrr -> rr
void	optimize_procedure(t_lst **lst_procedure)
{
	(void)lst_procedure;
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
