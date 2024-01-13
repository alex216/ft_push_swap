/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:31:29 by yliu              #+#    #+#             */
/*   Updated: 2024/01/13 19:30:41 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXIT_ERROR -1

# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

int	main(int argc, char **argv);

// utils/utils.c
void	del(void *pointer);
void	*create_record(char *str);
void	free_then_exit(void **double_pointer);
int		get_int_value_of(t_lst *pointer);
char	*get_char_value_of(t_lst *pointer);
ssize_t	create_new_dl_lst(t_lst **stack_a, t_record *record_p);
int	append_to_procedure(t_lst **lst_procedure, char *string);

// utils/argv_to_lst.c
void	argv_to_lst(int argc, char **argv, t_lst **lst_pp);
void	pf_debug(void);

// ope_two_node.c
ssize_t	ope_two_node(t_lst **stack_a, t_lst **lst_procedure);

// ope_three_node.c
ssize_t	ope_three_node(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure);

// ope_five_node.c
ssize_t	ope_five_node(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure);

// basic_stack_operation.c
void operate_swap_top_and_second_top(t_lst **lst);
void operate_rotate_top_and_tail(t_lst **lst);
void operate_rev_rotate_top_and_tail(t_lst **lst);

// operate_stack_a.c
void	operate_sa(t_lst **stack_a, t_lst **lst_procedure);
void	operate_ra(t_lst **stack_a, t_lst **lst_procedure);
void	operate_rra(t_lst **stack_a, t_lst **lst_procedure);

// operate_stack_b.c
void	operate_sb(t_lst **stack_b, t_lst **lst_procedure);
void	operate_rb(t_lst **stack_b, t_lst **lst_procedure);
void	operate_rrb(t_lst **stack_b, t_lst **lst_procedure);
void	operate_pb(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure);

// operate_both_stack.c
void	operate_ss(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure);
void	operate_rr(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure);
void	operate_rrr(t_lst **stack_a, t_lst **stack_b, t_lst **lst_procedure);

#endif
