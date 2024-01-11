/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:32:48 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 18:35:44 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static ssize_t	has_duplicate(t_lst *i)
{
	t_lst	*k;

	while (!i->is_sentinel)
	{
		k = i->prev_p;
		while (!k->is_sentinel)
		{
			if (k->payload_p->int_data == i->payload_p->int_data)
				return (false);
			k = k->prev_p;
		}
		i = i->next_p;
	}
	return (true);
}

static char	**convert_argv_to_str(const char *src_str)
{
	char	**malloced_str;

	malloced_str = ft_split(src_str, ' ');
	if (!malloced_str)
		return (NULL);
	return (malloced_str);
}

static ssize_t	check_digital_input(const char *string)
{
	char	*tmp_str;
	int		strncmp_res;

	tmp_str = ft_itoa(ft_atoi(string));
	if (!tmp_str)
		return(false);
	strncmp_res = ft_strncmp(string, tmp_str, ft_strlen(string));
	free(tmp_str);
	if (strncmp_res == 0)
		return(true);
	else
		return(false);
}

static ssize_t	process_input(t_lst **stack_a_pp, char *word)
{
	t_record	*record_p;
	t_lst		*t_lst_p;

	if (!check_digital_input(word))
		return (false);
	record_p = create(word);
	if (stack_a_pp == NULL || *stack_a_pp == NULL)
	{
		*stack_a_pp = ft_dl_lstnew(record_p);
		if (!stack_a_pp)
			return (false);
	}
	else
	{
		t_lst_p = ft_dl_lstcreate(record_p, false);
		if (!t_lst_p)
			return (false);
		ft_dl_lstadd_back(stack_a_pp, t_lst_p);
	}
	return (true);
}

void	argv_to_lst(int argc, char **argv, t_lst **stack_a_pp)
{
	char		**malloced_arg;
	size_t		i;

	if (argc <= 1)
		exit(0);
	argv++;
	while(*argv)
	{
		malloced_arg = convert_argv_to_str(*argv);
		if (!malloced_arg)
			exit(EXIT_FAILURE);
		i = 0;
		while (malloced_arg[i])
			if (!process_input(stack_a_pp, malloced_arg[i++]))
				exit(EXIT_FAILURE);
		argv++;
		while (i > 0)
			free(malloced_arg[--i]);
		free(malloced_arg);
	}
	if (has_duplicate(*stack_a_pp) == false)
		exit(EXIT_FAILURE);
}
