/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:31:29 by yliu              #+#    #+#             */
/*   Updated: 2023/12/24 22:59:12 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXIT_ERROR -1

# include <stdlib.h>
# include <stdbool.h>

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/libft.h"

int	main(int argc, char **argv);

// utils/utils.c
void		del(void *pointer);
void		*create(char *str);
void		free_then_exit(void **double_pointer);

// utils/argv_to_lst.c
void	argv_to_lst(int argc, char **argv, t_lst **lst_pp);
void	pf_debug(void);

#endif
