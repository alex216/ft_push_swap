/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:32:48 by yliu              #+#    #+#             */
/*   Updated: 2024/01/24 16:52:06 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static ssize_t	_has_duplicate_value(t_lst *iter_p);
static char	**_convert_argv_to_str(const char *src_str);
static ssize_t	_check_digital_input(const char *string);
static int	_handle_abnormal_input();
void	argv_to_lst(int argc, char **argv, t_lst **stack_a);

static ssize_t	_has_duplicate_value(t_lst *iter_p)
{
	t_lst	*temp_p;

	while (!iter_p->is_sentinel)
	{
		temp_p = iter_p->prev_p;
		while (!temp_p->is_sentinel)
		{
			if (get_int_value_of(temp_p) == get_int_value_of(iter_p))
				return (false);
			temp_p = temp_p->prev_p;
		}
		iter_p = iter_p->next_p;
	}
	return (true);
}

static char	**_convert_argv_to_str(const char *src_str)
{
	char	**malloced_str;

	malloced_str = ft_split(src_str, ' ');
	if (!malloced_str)
		return (NULL);
	return (malloced_str);
}

static ssize_t	_check_digital_input(const char *string)
{
	char	*tmp_str;
	int		strncmp_res;

	tmp_str = ft_itoa(ft_atoi(string));
	if (!tmp_str)
		return(false);
	strncmp_res = ft_strncmp(string, tmp_str, ft_strlen(string));
	free(tmp_str);
	if (strncmp_res)
		return(false);
	else
		return(true);
}

static int	_handle_abnormal_input()
{
	ft_printf("Error\n");
	return (true);
}

void	argv_to_lst(int argc, char **argv, t_lst **stack_a)
{
	char		**malloced_arg;
	size_t		i;

	if (argc <= 1)
		exit(0);
	argv++;
	while(*argv)
	{
		malloced_arg = _convert_argv_to_str(*argv);
		if (!malloced_arg)
			exit(EXIT_FAILURE);
		i = 0;
		while (malloced_arg[i])
		{
			if (!_check_digital_input(malloced_arg[i]))
				exit(_handle_abnormal_input());
			if (!ft_dl_lstappend(stack_a, create_record(malloced_arg[i++])))
				exit(EXIT_FAILURE);
		}
		argv++;
		while (i > 0)
			free(malloced_arg[--i]);
		free(malloced_arg);
	}
	if (!_has_duplicate_value(*stack_a))
		exit(_handle_abnormal_input());
}
