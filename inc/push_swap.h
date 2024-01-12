/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:31:29 by yliu              #+#    #+#             */
/*   Updated: 2024/01/12 15:37:28 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXIT_ERROR -1

# include <stdlib.h>
# include <stdbool.h>

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

int	main(int argc, char **argv);

// utils/utils.c
void	del(void *pointer);
void	*create_record(char *str);
void	free_then_exit(void **double_pointer);
int	get_int_value_of(t_lst *pointer);
char	*get_int_char_of(t_lst *pointer);
ssize_t	create_new_dl_lst(t_lst **lst_a, t_record *record_p);

// utils/argv_to_lst.c
void	argv_to_lst(int argc, char **argv, t_lst **lst_pp);
void	pf_debug(void);

// ope_three_node.c
ssize_t	ope_three_node(t_lst **lst_a, t_lst **lst_b, t_lst **lst_procedure);

#endif
