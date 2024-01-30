/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_kari.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:23:49 by yliu              #+#    #+#             */
/*   Updated: 2024/01/30 15:03:52 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	_put_data_to_ope_dictionary(t_operation_dictionary ope_dictionary[NUMBER_OPERATIONS])
{
	ope_dictionary[0].operation_name = "sa";
	ope_dictionary[1].operation_name = "sb";
	ope_dictionary[2].operation_name = "ss";
	ope_dictionary[3].operation_name = "pa";
	ope_dictionary[4].operation_name = "pb";
	ope_dictionary[5].operation_name = "ra";
	ope_dictionary[6].operation_name = "rb";
	ope_dictionary[7].operation_name = "rr";
	ope_dictionary[8].operation_name = "rra";
	ope_dictionary[9].operation_name = "rrb";
	ope_dictionary[10].operation_name = "rrr";
	ope_dictionary[0].operation_function = operate_sa;
	ope_dictionary[1].operation_function = operate_sb;
	ope_dictionary[2].operation_function = operate_ss;
	ope_dictionary[3].operation_function = operate_pa;
	ope_dictionary[4].operation_function = operate_pb;
	ope_dictionary[5].operation_function = operate_ra;
	ope_dictionary[6].operation_function = operate_rb;
	ope_dictionary[7].operation_function = operate_rr;
	ope_dictionary[8].operation_function = operate_rra;
	ope_dictionary[9].operation_function = operate_rrb;
	ope_dictionary[10].operation_function = operate_rrr;
}

static bool	_validate_operation(char *ope_name, char *input)
{
	size_t len;

	len = ft_strlen(input);
	return (!ft_strncmp(ope_name, input, len - 1) && input[len - 1] == '\n');
}

static bool _exec_valid_operation(
	const t_operation_dictionary ope_dict[NUMBER_OPERATIONS],
	t_lst **stack_a,
	t_lst **stack_b,
	t_lst **lst_procedure,
	char *string)
{
	int	i;

	i = 0;
	while (i < NUMBER_OPERATIONS)
	{
		if (_validate_operation(ope_dict[i].operation_name, string))
			return (ope_dict[i].operation_function(stack_a, stack_b, lst_procedure));
		i++;
	}
	return (false);
}

int main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	t_lst	*lst_procedure;
    ssize_t read_bytes;
	t_operation_dictionary ope_dictionary[NUMBER_OPERATIONS];

	stack_a = NULL;
	stack_b = NULL;
	lst_procedure = NULL;
	(void)stack_b;
	(void)lst_procedure;
	_put_data_to_ope_dictionary(ope_dictionary);
	argv_to_lst(argc, argv, &stack_a);
	char	read_buf[MAX_READ_SIZE];
 //    while (1)
	// {
        read_bytes = read(STDIN_FILENO, &read_buf, MAX_READ_SIZE);
        if (read_bytes <= 0)
			exit(EXIT_FAILURE);
		if (read_bytes >= MAX_READ_SIZE)
			exit(handle_abnormal_input());
		read_buf[read_bytes] = '\0';
		if (!_exec_valid_operation(ope_dictionary, &stack_a, &stack_b, &lst_procedure, read_buf))
			exit(handle_abnormal_input());
    // }
	if (is_ascending_order(stack_a))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
    return 0;
}
