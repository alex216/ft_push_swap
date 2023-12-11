/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_pf_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:31:52 by yliu              #+#    #+#             */
/*   Updated: 2023/12/11 15:12:14 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"
#include "../../inc/libft.h"

void	ft_dl_pf_lst(t_dl_lst *lst_p)
{
	ft_printf("#####start#####\n[->]");
	while (lst_p->is_sentinel != true)
	{
		ft_printf("%d", lst_p->int_data);
		lst_p = lst_p->next_p;
		if (lst_p->is_sentinel != true)
			ft_printf(" -> ");
	}
	ft_printf("\n[<-]");
	lst_p = lst_p->prev_p;
	while (lst_p->is_sentinel != true)
	{
		ft_printf("%d", lst_p->int_data);
		lst_p = lst_p->prev_p;
		if (lst_p->is_sentinel != true)
			ft_printf(" -> ");
	}
	ft_printf("\n");
	return ;
}
