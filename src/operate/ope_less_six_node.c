/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_less_six_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:19:28 by yliu              #+#    #+#             */
/*   Updated: 2024/01/20 18:12:13 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
# include "push_swap.h"

static ope_p	*_define_function_pointer(void);
static bool	_process_finish_dfs(t_lst **a, t_lst **b, t_lst **ans, t_lst **tmp);
static void	_exec_operation(int i,t_lst **a, t_lst **b, t_lst **tmp);
void	ope_less_six_node(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure);

static ope_p	*_define_function_pointer(void)
{
	static ope_p ope_array[OPERATION_NUMBER];

	ope_array[0] = operate_sa;
	ope_array[1] = operate_sb;
	ope_array[2] = operate_ss;
	ope_array[3] = operate_pa;
	ope_array[4] = operate_pb;
	ope_array[5] = operate_ra;
	ope_array[6] = operate_rb;
	ope_array[7] = operate_rr;
	ope_array[8] = operate_rra;
	ope_array[9] = operate_rrb;
	ope_array[10] = operate_rrr;
	return (ope_array);
}

static bool	_process_finish_dfs(t_lst **a, t_lst **b, t_lst **ans, t_lst **tmp)
{
	if (!*ans || ft_dl_lstsize(*tmp) < ft_dl_lstsize(*ans))
	{
		ft_dl_lstclear(ans, *del_push_swap);
		*ans = ft_dl_lstdup(tmp);
	}
	free_all(a, b, tmp);
	return (true);
}

static void	_exec_operation(int i,t_lst **a, t_lst **b, t_lst **tmp)
{
	ope_p *operation_array;

	operation_array = _define_function_pointer();
	operation_array[i](a, b, tmp);
}

static bool	_dfs(int life, t_lst **a, t_lst **b, t_lst **ans, t_lst **tmp)
{
	int	i;
	t_lst	*new_a;
	t_lst	*new_b;
	t_lst	*new_tmp;

	life--;
	if (!life)
		return (true);
	if (is_ascending_order(*a) && !*b)
		return (_process_finish_dfs(a, b, ans, tmp));
	i = 0;
	while (i < OPERATION_NUMBER)
	{
		new_a = ft_dl_lstdup(a);
		new_b = ft_dl_lstdup(b);
		new_tmp = ft_dl_lstdup(tmp);
		_exec_operation(i, &new_a, &new_b, &new_tmp);
		_dfs(life, &new_a, &new_b, ans, &new_tmp);
		i++;
	}
	free_all(a, b, tmp);
	return (true);
}

void	ope_less_six_node(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure)
{
	t_lst	*tmp;
	int	life;

	tmp = NULL;
	
	life = 4;
	if (!_dfs(life, stack_a, stack_b, lst_procedure, &tmp))
		exit(EXIT_FAILURE);
	return ;
}
