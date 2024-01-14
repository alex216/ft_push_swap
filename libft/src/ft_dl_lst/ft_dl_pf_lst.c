/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_pf_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:31:52 by yliu              #+#    #+#             */
/*   Updated: 2024/01/14 00:19:30 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	print_ascending_direction(t_lst *lst_p, void *(*return_printable)(t_lst *))
{
	while (!lst_p->is_sentinel)
	{
		ft_printf("%s", return_printable(lst_p));
		lst_p = lst_p->next_p;
		ft_printf(" -> ");
	}
	ft_printf("[%d]", lst_p->is_sentinel);
	ft_printf(" -> %s", return_printable(lst_p->next_p));
}

static void	print_descending_direction(t_lst *lst_p, void *(*return_printable)(t_lst *))
{
	while (!lst_p->is_sentinel)
	{
		ft_printf("%s", return_printable(lst_p));
		lst_p = lst_p->prev_p;
		ft_printf(" -> ");
	}
	ft_printf("[%d]", lst_p->is_sentinel);
	ft_printf(" -> %s", return_printable(lst_p->prev_p));
}

void	ft_dl_pf_lst(t_lst *lst_p, void *(*return_printable)(t_lst *))
{
	if (!lst_p || !(*return_printable))
		return ;
	ft_printf("#####start#####[size:%d]\n" , ft_dl_lstsize(lst_p));
	ft_printf("[->]");
	print_ascending_direction(lst_p, return_printable);
	ft_printf("\n");
	ft_printf("[<-]");
	print_descending_direction(lst_p->prev_p->prev_p, return_printable);
	ft_printf("\n");
	return ;
}
