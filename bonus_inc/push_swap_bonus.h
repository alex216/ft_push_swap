/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:06:11 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 20:14:10 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
#define PUSH_SWAP_BONUS_H

# include "push_swap.h"

# define NUMBER_OPERATIONS 11
# define MAX_READ_SIZE 5

typedef bool	(*ope_p)(t_lst **, t_lst **, t_lst **);

typedef struct s_operation_dictionary {
	size_t	index;
	char	*operation_name;
	bool	(*operation_function)(t_game_lists *game);
}			t_operation_dictionary;

int	main(int argc, char **argv);

#endif
