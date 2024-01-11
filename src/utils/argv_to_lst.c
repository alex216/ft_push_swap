/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:32:48 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 15:50:39 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdlib.h>

//	memo:
//	check_duplicate [✔]
// 		t_lst *				->		ssize_t(0 ,1)
//
//	convert_argv_to_str [✔]
//		char *				->		char **
//
//	check_digital_input [✔]
//		const char *		->		ssize_t(-1, 0, 1)

static ssize_t	check_duplicate(t_lst *iter_p)
{
	const t_lst	*last_p;

	last_p = ft_dl_lstlast(iter_p);
	while (iter_p->next_p->is_sentinel != 0)
	{
		if (iter_p->payload_p->int_data == last_p->payload_p->int_data)
			return (EXIT_FAILURE);
		iter_p = iter_p->next_p;
	}
	return (EXIT_SUCCESS);
}

static char	**convert_argv_to_str(const char *src_str)
{
	char	**malloced_str;

	malloced_str = ft_split(src_str, ' ');
	if (malloced_str == NULL)
		return (NULL);

	// // debug print
	// int i = 0;
	// while (malloced_str[i] != NULL)
	// {
	// 	ft_printf("%s\n", malloced_str[i]);
	// 	i++;
	// }
	// // debug end

	return (malloced_str);
}

static ssize_t	check_digital_input(const char *src_str)
{
	char	*tmp_str;
	int		strncmp_res;

	tmp_str = ft_itoa(ft_atoi(src_str));
	if (tmp_str == NULL)
		return(EXIT_ERROR);
	strncmp_res = ft_strncmp(src_str, tmp_str, ft_strlen(src_str));
	free(tmp_str);
	if (strncmp_res != 0)
		return(EXIT_FAILURE);
	else
		return(EXIT_SUCCESS);
}

void	argv_to_lst(int argc, char **argv, t_lst **stack_a_pp)
{
	char		**malloced_arg;
	size_t		i;
	t_lst		*t_lst_p;
	t_record	*record_p;

	if (argc <= 1)
		exit(0);
	argv++;
	while(*argv != NULL)
	{
		malloced_arg = convert_argv_to_str(*argv);
		if (malloced_arg == NULL)
			free_then_exit((void **)stack_a_pp);
		i = 0;
		while (malloced_arg[i] != NULL)
		{
			// check digit
			check_digital_input(malloced_arg[i]);

			// create t_record
			record_p = create(malloced_arg[i]);

			if (stack_a_pp == NULL || *stack_a_pp == NULL)
				*stack_a_pp = ft_dl_lstnew(record_p);
			else
			{
				t_lst_p = ft_dl_lstcreate(record_p, false);
				ft_dl_lstadd_back(stack_a_pp, t_lst_p);
			}
	
			// debug print
			ft_dl_pf_lst(*stack_a_pp);
			i++;
		}
		argv++;
		while (i > 0)
			free(malloced_arg[--i]);
		free(malloced_arg);
	}
	if (check_duplicate(*stack_a_pp) == EXIT_FAILURE)
		free_then_exit((void **)stack_a_pp);
}
