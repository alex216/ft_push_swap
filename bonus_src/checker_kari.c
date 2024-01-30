/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_kari.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:23:49 by yliu              #+#    #+#             */
/*   Updated: 2024/01/29 18:09:15 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../bonus_inc/push_swap_bonus.h"
#include "push_swap_bonus.h"

// static	bool _check_valid_operation(char *string)
// {
// 	const char *operation_array[]= {"sa", "ra", "rra", "pa", "sb", "rb", "rrb", "pb", "rr", "rrr", "ss"};
// 	int	i;
//
// 	i = 0;
// 	while (i < NUMBER_OPERATIONS)
// 	{
// 		if (ft_strncmp(operation_array[i], string, ft_strlen(string)))
// 			return (true);
// 	}
// 	return (false);
// }

int main(int argc, char **argv)
{
	t_lst	*stack_a;
	// t_lst	*stack_b;
	t_lst	*lst_procedure;
    ssize_t read_bytes;
	char	dst[4];

	stack_a = NULL;
	// stack_b = NULL;
	lst_procedure = NULL;
	argv_to_lst(argc, argv, &stack_a);
	ft_dl_pf_lst(stack_a, get_pointer_to_print);

    while (1)
	{
		char	tmp[10];
        read_bytes = read(STDIN_FILENO, &tmp, 5);
		ft_printf("errno is : %d\n", errno);
		ft_printf("read ret val is : %d\n", read_bytes);
        if (read_bytes <= 0) {
			exit(EXIT_FAILURE);
        }
		ft_strlcpy(dst, tmp, 4);

        // write(STDOUT_FILENO, tmp, ft_strlen(tmp));
		append_to_procedure(&lst_procedure, dst);

    }
	// debug
	ft_dl_pf_lst(lst_procedure, get_pointer_to_print);

	// 
    return 0;
}
