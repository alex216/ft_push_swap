/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_query1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:34:00 by yliu              #+#    #+#             */
/*   Updated: 2024/02/07 16:34:05 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_last_operation_is(const char *str, const t_lst **lst)
{
	char	*last_cmd;

	last_cmd = get_char_of(ft_dl_lstlast(*lst));
	return (!ft_strncmp(last_cmd, str, ft_strlen(str)));
}
