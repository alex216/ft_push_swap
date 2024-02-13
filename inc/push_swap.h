/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:31:29 by yliu              #+#    #+#             */
/*   Updated: 2024/02/09 17:59:41 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <stddef.h>

# define EXIT_ERROR -1
# define OPERATION_NUMBER 11

typedef struct s_record
{
	int		int_data;
	size_t	index;
	char	*char_content;
	void	*omni_p;
}			t_record;

typedef struct s_game_lists
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	t_lst	*lst_procedure;
}			t_game_lists;

typedef struct s_node
{
	t_lst	*lst_p;
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		min_cost;
}			t_node;

//////////////////////////////////////////
/// main
// main.c
int			main(int argc, char **argv);
// argv_to_lst.c
void		copy_argv_to_lst(int argc, char **argv, t_lst **lst_pp);
// argv_to_lst_helper.c
char		**convert_argv_to_str(const char *src_str);
ssize_t		has_duplicate_value(const t_lst *iter_p);
// calculate_procedure.c
void		calculate_procedure(t_game_lists *game);
//////////////////////////////////////////
/// strategy
// ope_three_four_five_node.c
void		ope_three_four_five_node(t_game_lists *game);
// ope_select_insert.c
void		ope_select_insert(t_game_lists *game);
// ope_bubble_sort.c
void		ope_bubble_sort(t_game_lists *game);
// quick_sort.c
void		ope_quick_sort(t_game_lists *game);
//////////////////////////////////////////
// select_push_insert.c 5
void		rotate_both_stack_for_push(t_node *node_info,
				t_game_lists *game);
// utils/append_sa_if_needed.c
void		append_sa_if_needed(t_game_lists *game);
//////////////////////////////////////////
/// utils
// utils_struct_get_contest.c 5
size_t		get_index_of(const t_lst *pointer);
int			get_int_value_of(const t_lst *pointer);
char		*get_char_of(const t_lst *pointer);
size_t		get_rotate_cost(t_lst **lst_pp, const t_lst *lst_p);
size_t		get_min_cost_to_push(t_lst **lst_pp, const t_lst *iter_p);
// utils_list_query.c 5
bool		is_ascending_order(const t_lst *iter_p);
size_t		return_num_to_ascending(t_lst **lst_pp, const t_lst *node_p);
size_t		return_num_to_descending(t_lst **lst_pp, const t_lst *node_p);
// utils_list_query1.c 4
bool		check_last_operation_is(const char *str, const t_lst **lst);
void		create_node_info_to_insert_to_a(t_lst *iter_p, t_node *node,
				t_game_lists *game);
void		create_node_info_to_insert_to_b(t_lst *iter_p, t_node *node,
				t_game_lists *game);
// utils_list_cmds.c 2
void		sort_stack_use_ra_rra(t_lst **stack, t_game_lists *game);
void		sort_stack_use_rb_rrb(t_lst **stack, t_game_lists *game);
// utils_struct_modify.c 3
void		del_push_swap(void *pointer);
void		*create_record(const char *str);
void		append_to_procedure(t_lst **lst_procedure, const char *string);
// utils_trivial.c 5
void		initialize_game_list(t_game_lists *game);
int			handle_abnormal_input(void);
void		free_all_lists(t_game_lists *game);
void		print_procedure(const t_lst *i_p);
void		optimize_procedure(t_lst **lst_procedure);
//////////////////////////////////////////
/// operate
// operate_both_stack.c
bool		operate_ss(t_game_lists *game);
bool		operate_rr(t_game_lists *game);
bool		operate_rrr(t_game_lists *game);
// operate_stack_a.c
bool		operate_sa(t_game_lists *game);
bool		operate_ra(t_game_lists *game);
bool		operate_rra(t_game_lists *game);
bool		operate_pa(t_game_lists *game);
// operate_stack_b.c
bool		operate_sb(t_game_lists *game);
bool		operate_rb(t_game_lists *game);
bool		operate_rrb(t_game_lists *game);
bool		operate_pb(t_game_lists *game);
// basic_stack_ope1.c
void		operate_swap_top_and_second_top(t_lst **lst);
void		operate_rotate_top_and_tail(t_lst **lst);
void		operate_rev_rotate_top_and_tail(t_lst **lst);
// basic_stack_ope2.c
bool		operate_push_top_to_another_stack(t_lst **src, t_lst **dst);
//////////////////////////////////////////
// utils_basic.c
int			ft_min(int a, int b);
int			ft_max(int a, int b);
int			ft_four_min(int a, int b, int c, int d);
// utils_debug.c
void		debug_func(const t_game_lists *game);
void		print_index(const t_lst **lst_pp);

#endif
