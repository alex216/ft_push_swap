/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:23:49 by yliu              #+#    #+#             */
/*   Updated: 2024/03/26 13:06:03 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	_put_data_to_ope_dictionary(
	t_operation_dictionary ope_dictionary[NUMBER_OPERATIONS])
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
	int	len;

	len = ft_strlen(input);
	return (!ft_strncmp(ope_name, input, len - 1) && input[len - 1] == '\n');
}

static bool	_exec_valid_operation(char *string, t_game_lists *game)
{
	int						i;
	t_operation_dictionary	ope_dict[NUMBER_OPERATIONS];

	_put_data_to_ope_dictionary(ope_dict);
	i = 0;
	while (i < NUMBER_OPERATIONS)
	{
		if (_validate_operation(ope_dict[i].operation_name, string))
			return (ope_dict[i].operation_function(game));
		i++;
	}
	return (false);
}

static void	_read_loop(t_game_lists *game)
{
	char	*cmd_string;

	while (true)
	{
		cmd_string = get_next_line(STDIN_FILENO);
		if (!cmd_string)
			break ;
		if (!_exec_valid_operation(cmd_string, game))
			exit(handle_abnormal_input());
		free(cmd_string);
	}
}

int	main(int argc, char **argv)
{
	t_game_lists	game_lists;

	game_lists.stack_a = NULL;
	game_lists.stack_b = NULL;
	game_lists.lst_procedure = NULL;
	copy_argv_to_lst(argc, argv, &game_lists.stack_a);
	_read_loop(&game_lists);
	if (ft_dl_lstsize(game_lists.stack_b) == 0 && is_ascending_order(game_lists.stack_a))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	free_all_lists(&game_lists);
	return (0);
}
