/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_two_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:21:40 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 13:16:27 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ope_two_node(t_game_lists *game_lists)
{
	if (get_int_value_of(game_lists->stack_a) > get_int_value_of(game_lists->stack_a->next_p))
		operate_sa(game_lists);
	return ;
}
