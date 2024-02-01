/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_argv_to_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:32:48 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 16:10:02 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static ssize_t	_check_digital_input(const char *string)
{
	char	*tmp_str;
	int		strncmp_res;

	tmp_str = ft_itoa(ft_atoi(string));
	if (!tmp_str)
		return (false);
	strncmp_res = ft_strncmp(string, tmp_str, ft_strlen(string));
	free(tmp_str);
	if (strncmp_res)
		return (false);
	else
		return (true);
}

static size_t	_append_malloc_str_to_lst(char **malloced_arg, t_lst **stack_a)
{
	size_t	i;

	i = 0;
	while (malloced_arg[i])
	{
		if (!_check_digital_input(malloced_arg[i]))
			exit(handle_abnormal_input());
		if (!ft_dl_lstappend(stack_a, create_record(malloced_arg[i])))
			exit(EXIT_FAILURE);
		i++;
	}
	return (i);
}

static size_t	_count_how_large_the_new_node_is(t_lst **stack_a, t_lst *lst_p)
{
	t_lst	*iter_p;
	size_t	larger;

	iter_p = *stack_a;
	larger = 1;
	while (iter_p->is_sentinel == false)
	{
		if (get_int_value_of(iter_p) < get_int_value_of(lst_p))
			larger++;
		iter_p = iter_p->next_p;
	}
	return (larger);
}

static void	_compress_array(t_lst **stack_a)
{
	t_lst	*iter_p;

	iter_p = *stack_a;
	while (iter_p->is_sentinel == false)
	{
		iter_p->payload_p->index = _count_how_large_the_new_node_is(stack_a,
				iter_p);
		iter_p = iter_p->next_p;
	}
}

void	copy_argv_to_lst(int argc, char **argv, t_lst **stack_a)
{
	char	**malloced_arg;
	size_t	i;

	if (argc <= 1)
		exit(0);
	argv++;
	while (*argv)
	{
		malloced_arg = convert_argv_to_str(*argv);
		if (!malloced_arg)
			exit(EXIT_FAILURE);
		if (!*malloced_arg)
			exit(handle_abnormal_input());
		i = _append_malloc_str_to_lst(malloced_arg, stack_a);
		while (i > 0)
			free(malloced_arg[--i]);
		free(malloced_arg);
		argv++;
	}
	if (has_duplicate_value(*stack_a))
		exit(handle_abnormal_input());
	_compress_array(stack_a);
}
