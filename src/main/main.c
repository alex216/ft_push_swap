/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:20:49 by yliu              #+#    #+#             */
/*   Updated: 2023/12/18 16:46:09 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// TODO: add data to dl_lst
// todo: duplicates, incorrectly formatted.
// TODO: algorithm.
// todo: t_dl_lst -> t_lst
//

static void	check_duplicate_list(t_dl_lst	*list_p);
{
	// t_dl_lst	*last_p;
	// t_dl_lst	*iter_p;
	//
	// ft_dl_lstlast(lst_p);
	// iter_p = list_p;
	// while (iter_p->next_p->is_sentinal != 0)
	//
}

static t_dl_lst	*validate_input(int argc, char **argv, t_dl_lst **lst_pp)
{
	int	strncmp_res;

	if (argc <= 1)
		exit(NULL);
	argv++;
	while (*argv != NULL)
	{
		char *v = ft_itoa(ft_atoi(*argv));
		strncmp_res = ft_strncmp(*argv, v, ft_strlen(*argv));
		free(v);
		if (strncmp_res != 0)
			exit(ft_printf("Error\n"));
		argv++;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_dl_lst	*lst_a;
	t_dl_lst	*lst_b;
	t_dl_lst	*lst_procedure;

	validate_input(argc, argv, &lst_a);
	check_duplicate_list(&lst_a);
	// calculate_task(&lst_a, &lst_b, &lst_procedure);
	// print_list(&lst_procedure);
	return (0);
}
