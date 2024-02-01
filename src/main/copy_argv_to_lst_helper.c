/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_argv_to_lst_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:53:21 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 16:47:21 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**convert_argv_to_str(const char *src_str)
{
	char	**malloced_str;

	malloced_str = ft_split(src_str, ' ');
	if (!malloced_str)
		return (NULL);
	return (malloced_str);
}

ssize_t	has_duplicate_value(const t_lst *iter_p)
{
	t_lst	*temp_p;

	while (!iter_p->is_sentinel)
	{
		temp_p = iter_p->prev_p;
		while (!temp_p->is_sentinel)
		{
			if (get_int_value_of(temp_p) == get_int_value_of(iter_p))
				return (true);
			temp_p = temp_p->prev_p;
		}
		iter_p = iter_p->next_p;
	}
	return (false);
}
