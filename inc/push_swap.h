/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:31:29 by yliu              #+#    #+#             */
/*   Updated: 2024/02/01 15:31:33 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
# define EXIT_ERROR -1
# define OPERATION_NUMBER 11

# ifndef t_record
typedef struct s_record	t_record;
# endif

# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

typedef struct s_record {
	int		int_data;
	size_t	index;
	char	*char_content;
	void	*omni_p;
}			t_record;

typedef bool	(*ope_p)(t_lst **, t_lst **, t_lst **);

typedef struct s_operation_dictionary {
	size_t	index;
	char	*operation_name;
	bool	(*operation_function)(t_lst **, t_lst **, t_lst **);
}			t_operation_dictionary;

typedef struct s_game_lists {
	t_lst	*stack_a;
	t_lst	*stack_b;
	t_lst	*lst_procedure;
}			t_game_lists;

//////////////////////////////////////////
// main.c
int	main(int argc, char **argv);

// utils/argv_to_lst.c
void	argv_to_lst(int argc, char **argv, t_lst **lst_pp);

//////////////////////////////////////////
// push_insert.c
void	execute_optimized_push(int minimum, int ra_num, t_game_lists *game_lists);

// utils/append_sa_if_needed.c
void	append_sa_if_needed(t_game_lists *game_lists);

// utils/utils_struct_modify.c
size_t	get_index_of(const t_lst *pointer);
int	get_int_value_of(const t_lst *pointer);
char	*get_char_of(const t_lst *pointer);
void	*get_pointer_to_print(const t_lst *lst_p);

//////////////////////////////////////////
/// strategy
// ope_three_four_five_node.c
void	ope_three_four_five_node(t_game_lists *game_lists);
void	sort_stack_using_only_ra_or_rra_in_fastest_way_in_a(t_lst **lst_pp, t_game_lists *game_lists);
void	sort_stack_using_only_ra_or_rra_in_fastest_way_in_b(t_lst **lst_pp, t_game_lists *game_lists);
// ope_long.c
void	ope_long(t_game_lists *game_lists);

//////////////////////////////////////////
/// operate
// operate_both_stack.c
bool	operate_ss(t_game_lists *game_lists);
bool	operate_rr(t_game_lists *game_lists);
bool	operate_rrr(t_game_lists *game_lists);
// operate_stack_a.c
bool	operate_sa(t_game_lists *game_lists);
bool	operate_ra(t_game_lists *game_lists);
bool	operate_rra(t_game_lists *game_lists);
bool	operate_pa(t_game_lists *game_lists);
// operate_stack_b.c
bool	operate_sb(t_game_lists *game_lists);
bool	operate_rb(t_game_lists *game_lists);
bool	operate_rrb(t_game_lists *game_lists);
bool	operate_pb(t_game_lists *game_lists);
// basic_stack_ope1.c
void	operate_swap_top_and_second_top(t_lst **lst);
void	operate_rotate_top_and_tail(t_lst **lst);
void	operate_rev_rotate_top_and_tail(t_lst **lst);
// basic_stack_ope2.c
bool	operate_push_top_to_another_stack(t_lst **src_pp, t_lst **dst_pp);

//////////////////////////////////////////
/// utils
// utils_basic.c
int	ft_min(int a, int b);
int	ft_max(int a, int b);
int	ft_four_min(int a, int b, int c, int d);
// utils_debug.c
void	free_all(t_game_lists *game_lists);
void	debug_func(t_lst **a, t_lst **b, t_lst **tmp, char *, char *, char *);
void	print_index(t_lst **lst_pp);
int	handle_abnormal_input();
// utils_temp.c
bool	is_ascending_order(const t_lst *iter_p);
size_t return_number_to_rotate_ascending(t_lst **lst_pp, const t_lst *node_p);
size_t return_number_to_rotate_descending(t_lst **lst_pp, const t_lst *node_p);
bool	check_last_operation_is(const char *str, const t_lst **lst);
// utils_struct_modify.c
void	del_push_swap(void *pointer);
void	*create_record(const char *str);
void	append_to_procedure(t_lst **lst_procedure,const char *string);

#endif
