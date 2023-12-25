/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:20:49 by yliu              #+#    #+#             */
/*   Updated: 2023/12/25 14:45:29 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdlib.h>

// TODO: "1 2" 3 4 "5"
// todo: duplicates, incorrectly formatted.
// todo: algorithm.

int	main(int argc, char **argv)
{
	t_lst	*lst_a;
	// t_lst	*lst_b;
	// t_lst	*lst_procedure;

	lst_a = NULL;
	argv_to_lst(argc, argv, &lst_a);
	// calculate_task(&lst_a, &lst_b, &lst_procedure);
	// print_list(&lst_procedure);

	// free
	// ft_dl_lstclear(&lst_a, *del);
	return (0);
}
