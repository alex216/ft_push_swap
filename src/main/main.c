/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:20:49 by yliu              #+#    #+#             */
/*   Updated: 2023/12/11 11:40:56 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// TODO:
// 		doubly linked list
// 		this should be abstruct data type.
// 		this is a standard structure, therefore should be added to libft
// 			
// TODO: duplicates ,incorrectly formatted.
// TODO: algorithm.

// static int	validate_input(int argc, char **argv, doubly_linked_list *list)
static int	validate_input(int argc, char **argv)
{
	int	strncmp_res;

	if (argc <= 1)
		return (EXIT_FAILURE);
	argv++;
	while (*argv != NULL)
	{
		char *v = ft_itoa(ft_atoi(*argv));
		strncmp_res = ft_strncmp(*argv, v, ft_strlen(*argv));
		free(v);
	
		// error
		if (strncmp_res != 0)
			exit(ft_printf("Error\n"));
		argv++;
	}
	return (EXIT_SUCCESS);
}

// static initialize_list(doubly_linked_list *list)
// {
// 	ft_lstnew();
// }

int	main(int argc, char **argv)
{
	// doubly_linked_list	*list_a;
	// initialize_list(list_a);

	// validate_input(argc, argv, list_a);
	validate_input(argc, argv);
}
